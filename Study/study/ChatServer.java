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
		
		String welcomMessage = "서버접속 성공!!";
		
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
			
			System.out.println("User : "+ client.getInetAddress() +":"+client.getPort()+ "의 " + welcomMessage);			
		}

		public void run() {
			broadCast("User : "+ client.getInetAddress() +":"+client.getPort()+ "의 " + welcomMessage);
			while(true) {
				try {
					Object messageClient = dis.readUTF();				
					
					broadCast((String)messageClient);
					
				} catch (Exception e) {
					System.out.println("User : "+ client.getInetAddress() +":"+client.getPort()+ "이 채팅방을 떠났습니다.");	
					broadCast("User : "+ client.getInetAddress() +":"+client.getPort()+ "이 채팅방을 떠났습니다.");
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
			server = new ServerSocket(3001); // 서버 소켓을 열기
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("클라이언트 기다리는중...");
		
		while(true) {
			try {
				client = server.accept(); // block상태에서 client가 소켓에 들어오길 기다림
			} catch (Exception e) {				
			}
			System.out.println("클라이언트 접속");
			ChatServerThread newUser = new ChatServerThread(client);
			clients.add(newUser);
			newUser.start();
		}
	}
	
	public static void main(String[] args) {
		new ChatServer().start();	
		
	}
}