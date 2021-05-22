#include "RFID.h"

int CCONV RFID::AttachHandler(RFID R)
{
	int serialNo;
	const char *name;

	CPhidget_getDeviceName(R.rfid, &name);
	CPhidget_getSerialNumber(R.rfid, &serialNo);

	return 0;
}

int CCONV RFID::DetachHandler(RFID R)
{
	int serialNo;
	const char *name;

	CPhidget_getDeviceName(R.rfid, &name);
	CPhidget_getSerialNumber(R.rfid, &serialNo);

	return 0;
}

int CCONV RFID::ErrorHandler(RFID R)
{
	cout << "Error handled. " << R.errorCode << R.unknown << endl;
	return 0;
}

//Display the properties of the attached phidget to the screen.  We will be displaying the name, serial number and version of the attached device.
//We will also display the number of available digital outputs
/*
int display_properties(CPhidgetRFIDHandle phid)
{
int serialNo, version, numOutputs, antennaOn, LEDOn;
const char* ptr;

CPhidget_getDeviceType((CPhidgetHandle)phid, &ptr);
CPhidget_getSerialNumber((CPhidgetHandle)phid, &serialNo);
CPhidget_getDeviceVersion((CPhidgetHandle)phid, &version);

CPhidgetRFID_getOutputCount(phid, &numOutputs);
CPhidgetRFID_getAntennaOn(phid, &antennaOn);
CPhidgetRFID_getLEDOn(phid, &LEDOn);


cout << "%s\n" << ptr << endl;
cout << "Serial Number: " << serialNo << "Version:" << version << endl;
cout << "# Outputs: " << endl << endl << numOutputs << endl;
cout << "Antenna Status": antennaOn << Onboard << endl << "LED Status:" << LEDOn << endl;

return 0;
}*/

int RFID :: rfid_simple(RFID R)
{
	int result;
	const char *err;

	//Declare an RFID handle
	CPhidgetRFIDHandle R.rfid = 0;

	//create the RFID object
	CPhidgetRFID_create(&(R.rfid));

	//Set the handlers to be run when the device is plugged in or opened from software, unplugged or closed from software, or generates an error.
	CPhidget_set_OnAttach_Handler((CPhidgetHandle)R.rfid, R.AttachHandler, NULL);
	CPhidget_set_OnDetach_Handler((CPhidgetHandle)R.rfid, R.DetachHandler, NULL);
	CPhidget_set_OnError_Handler((CPhidgetHandle)R.rfid, R.ErrorHandler, NULL);

	//Registers a callback that will run if an output changes.
	//Requires the handle for the Phidget, the function that will be called, and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetRFID_set_OnOutputChange_Handler(R.rfid1, R.OutputChangeHandler, NULL);

	//Registers a callback that will run when a Tag is read.
	//Requires the handle for the PhidgetRFID, the function that will be called, and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetRFID_set_OnTag2_Handler(R.rfid1, R.TagHandler, NULL);

	//Registers a callback that will run when a Tag is lost (removed from antenna read range).
	//Requires the handle for the PhidgetRFID, the function that will be called, and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetRFID_set_OnTagLost2_Handler(R.rfid1, R.TagLostHandler, NULL);

	//open the RFID for device connections
	CPhidget_open((CPhidgetHandle)R.rfid, -1);

	//get the program to wait for an RFID device to be attached
	cout << "Waiting for RFID to be attached...." << endl;
	if ((result = CPhidget_waitForAttachment((CPhidgetHandle)R.rfid, 10000)))
	{
		CPhidget_getErrorDescription(result, &err);
		cout << "Problem waiting for attachment:" << err << endl;
		return 0;
	}

	//Display the properties of the attached RFID device
	//display_properties(rfid);

	CPhidgetRFID_setAntennaOn(R.rfid1, 1);

	//read RFID event data
	cout << "Reading.....\n" << endl;

	//keep displaying RFID event data until user input is read
	cout << "Press any key to continue" << endl;
	getchar();

	//toggle the digital output (when making this example I had an LED plugged into the digital output index 0
	CPhidgetRFID_setOutputState(R.rfid1, 0, 1);

	//keep displaying RFID event data until user input is read
	cout << "Press any key to continue" << endl;
	getchar();

	//toggle the digital output (when making this example I had an LED plugged into the digital output index 0
	CPhidgetRFID_setOutputState(R.rfid1, 0, 0);

	cout << "Press any key to end" << endl;
	getchar();

	//since user input has been read, this is a signal to terminate the program so we will close the phidget and delete the object we created
	cout << "Closing..." << endl;
	CPhidget_close((CPhidgetHandle)R.rfid);
	CPhidget_delete((CPhidgetHandle)R.rfid);

	//all done, exit
	return 0;
}