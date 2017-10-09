package studio6;

import jssc.*;

public class SerialComm {

	SerialPort port;

	private boolean debug;  // Indicator of "debugging mode"
	
	// This function can be called to enable or disable "debugging mode"
	void setDebug(boolean mode) {
		debug = mode;
	}	
	

	// Constructor for the SerialComm class
	public SerialComm(String name) throws SerialPortException {
		port = new SerialPort(name);		
		port.openPort();
		port.setParams(SerialPort.BAUDRATE_9600,
			SerialPort.DATABITS_8,
			SerialPort.STOPBITS_1,
			SerialPort.PARITY_NONE);
		
		debug = false; // Default is to NOT be in debug mode
	}
		
	// TODO: Add writeByte() method that you created in Studio 5
	
	public void writeByte(byte byt) throws SerialPortException{
		this.port.writeByte(byt);
		if(this.debug){
			System.out.printf("0x%02X", byt);
			System.out.println();
		}
	}
	
	public boolean available() throws SerialPortException {
		if(this.port.getInputBufferBytesCount() > 0) {
			return true;
		}else {
			return false;
		}
	}
	
	public byte readByte() throws SerialPortException {
		return this.port.readBytes()[0];
	}
	
	public static void main(String[] args) throws SerialPortException, InterruptedException {
		SerialComm comm = new SerialComm("COM4");
		comm.debug = true;
		while(true) {
			Thread.sleep(1000);
			if(comm.available()) {
				if(comm.debug) {
					System.out.printf("%02x", comm.readByte());
					System.out.println();
				}
			}
		}
		
	}
}