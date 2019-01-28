package com.ssafy;


import java.io.IOException;
import java.io.InputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class ChatConnect {
	protected String ip;
	protected int port;
	protected String name;
	
	private Socket s;
	private OutputStream out;
	private DataOutputStream oos;
	private InputStream in;
	private DataInputStream ois;
	private ChatClient cl;
	
	public ChatConnect(String ip, int port, String name, ChatClient cl) throws UnknownHostException, IOException {
		this.ip = ip;
		this.port = port;
		this.name = name;
		this.cl = cl;
		
		go();
		
	}


	public void go() {
		try {
			s = new Socket(ip, port);
			in = s.getInputStream();
			ois = new DataInputStream(in);
			out = s.getOutputStream();
			oos = new DataOutputStream(out);
			
			System.out.println("¿¬°á");
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void send(String msg) throws IOException {
		if (oos != null) {
			try {
				oos.writeUTF("[" + name + "] " +msg);
			} catch (Exception e) {
			}
		}
		
	}
	
	public void listen() {
		while(true) {
			try {
				String messageClient = ois.readUTF();
				System.out.println(messageClient);
				cl.ta.append(messageClient + "\n");
				
			} catch (Exception e) {
				return;
			}			
		}
	}
	
	
	
	public void close() throws IOException {
		oos.close();
		out.close();
		ois.close();
		in.close();
		s.close();
	}
	
}