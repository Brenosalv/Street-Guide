#include <phidget21.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

class RFID {

	protected:
		//Variaveis padrao
		void *userptr;
		int errorCode, INdex, State;
		const char *unknowm;
		char *tagval;

		//variaveis da biblioteca phidgets
		CPhidgetHandle rfid;
		CPhidgetRFID_Protocol proto;
		CPhidgetRFIDHandle rfid1;

	public:
		//declaração das funções;

		int CCONV AttachHandler(RFID);
		int CCONV DetachHandler(RFID);
		int CCONV ErrorHandler(RFID);
		int CCONV OutputChangeHandler(RFID);
		virtual int CCONV TagHandler(RFID) { return 0; }
		int CCONV TagLostHandler(RFID);
		int rfid_simple(RFID);
};