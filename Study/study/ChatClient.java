package com.ssafy;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.UnknownHostException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class ChatClient extends WindowAdapter implements ActionListener {

	private JFrame f;
	private JButton b1, b2;//��ư 
	private JTextField tf; // ����
	JTextArea ta; // ������
	private JPanel p;
	private static ChatConnect cc;
	
	public ChatClient(String ip, int port, String name) {
		createGUI();
		
	}
	
	public void createGUI() {
		f = new JFrame("Chat");
		f.setLayout(new BorderLayout()); //layout manager(��ġ������)����.add�ϴ� ������� ȭ�鿡 ����
		//f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //â�ݱ� ��ư ������ �� �� �� ����. �����ư ������ ���α׷� ����
		f.addWindowListener(this);
		
		ta = new JTextArea(5, 30);
		tf = new JTextField(25);
		ta.setEditable(false);
		ta.setBackground(Color.white);
		
		b1 = new JButton("send");
		b2 = new JButton("exit");
			
		tf.addActionListener(this);
		b1.addActionListener(this);
		b2.addActionListener(this);
		
		p = new JPanel(new GridLayout(11,2));
		
		p.add(b1);
		p.add(b2);
		
		JScrollPane pane = new JScrollPane(ta); // ��ũ�ѹ�
		Container c = f.getContentPane();//ȭ��󿡼� ContentPane������ �˾Ƴ�
		
		c.add(pane, "Center");
		c.add(p, "East");
		c.add(tf, "South");
		
		f.setSize(400,500);
		f.setVisible(true);
	}
	
	public void windowClosing(JButton b22) {
		exit();
	}
	
	void exit() {
		System.exit(0);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		Object o = e.getSource();
		if(o == b1 || o == tf) {
			String message = tf.getText();
			//ta.append(message);
			try {
				cc.send(message);
			} catch (Exception e2) {
				e2.printStackTrace();
			}
			tf.setText("");
			tf.requestFocus();
		}
		else if(o==b2) {
			try {
				cc.close();
				windowClosing(b2);
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
	}
	
	public static void main(String[] args) throws UnknownHostException, IOException {
		
		String name = "name2";
		ChatClient cl = new ChatClient("localhost", 3001, name);
		cc = new ChatConnect("localhost", 3001, name, cl);
		cc.listen();
		
	}

}