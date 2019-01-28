package com.ssafy;

import java.io.*;
import java.net.*;
import java.util.ArrayList;


public class ChatServer {
	
	ServerSocket server=null;
	Socket client=null;	
	ArrayList<ChatServerThread> clients = new ArrayList<>();
	
	class ChatServerThread extends Thread{
		OutputStream out;
		DataOutputStream dos;
		InputStream in;
		DataInputStream dis;
		Socket client;
		String clientName;
		
		String welcomMessage = "�������� ����!!";
		
		ChatServerThread(Socket client) {
			this.client = client;
			
			try {
				out = client.getOutputStream();
				in = client.getInputStream();
				dos = new DataOutputStream(out);			
				dis = new DataInputStream(in);
				
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			System.out.println("User : "+ client.getInetAddress() +":"+client.getPort()+ "�� " + welcomMessage);			
		}

		public void run() {
			broadCast("User : "+ client.getInetAddress() +":"+client.getPort()+ "�� " + welcomMessage);
			while(true) {
				try {
					Object messageClient = dis.readUTF();				
					
					broadCast((String)messageClient);
					
				} catch (Exception e) {
					System.out.println("User : "+ client.getInetAddress() +":"+client.getPort()+ "�� ä�ù��� �������ϴ�.");	
					broadCast("User : "+ client.getInetAddress() +":"+client.getPort()+ "�� ä�ù��� �������ϴ�.");
					return;					
				}			
			}
		}
	}
	
	
	public void broadCast(String msg) {
		OutputStream out=null;
		DataOutputStream dos=null;		
		
		for(int i=0;i<clients.size();i++) {
			try {
				out = clients.get(i).client.getOutputStream();
				dos = new DataOutputStream(out);				
				dos.writeUTF(msg);
			} catch (Exception e) {									
					clients.remove(i);				
				
			}
		}		
	}
	
	public void start() {
		try {
			server = new ServerSocket(3001); // ���� ������ ����
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("Ŭ���̾�Ʈ ��ٸ�����...");
		
		while(true) {
			try {
				client = server.accept(); // block���¿��� client�� ���Ͽ� ������ ��ٸ�
			} catch (Exception e) {				
			}
			System.out.println("Ŭ���̾�Ʈ ����");
			ChatServerThread newUser = new ChatServerThread(client);
			clients.add(newUser);
			newUser.start();
		}
	}
	
	public static void main(String[] args) {
		new ChatServer().start();	
		
	}
}