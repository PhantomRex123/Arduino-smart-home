#include <Arduino.h>
#include <ArduinoJson.h>


// COMMANDS
// AT
// OK
// AT + CSQ
// + CSQ: 7, 0
// OK
// AT + COPS ?
// +COPS : 0, 0, "TCI"
// OK
// AT + CCID
// 89981111000059380700
// OK
// AT + CMGF = 1
// OK
// ATD + +982122202059;
// OK
// ATH
// OK
// ATD + +989121220205;
// AT+DDET=1,100,0,0
// OK
// String

String configure();
String profileController(String option);
String getData();
String setData();
String makeCall(int number);
String sendSMS(int number, String message);
String DTMF();
String readSMS();

String getDataSIMCARDMODULE() {
    AT+GMI
    AT+GMM
    AT+GMR
    AT+CGMI
    AT+CGMM
        AT+CGMR
    AT+CIMI
    AT+CPAS

}

String BaudRate() {
    AT+IPR?
}

String contacts() {
    AT+CPBF
AT+CPBR=2
AT+CPBS=?
    AT+CPBW

}

String status(){
    AT+CREG?
    AT+CSQ
    AT+CFUN?
    AT+CALM?
    AT+CSCA?

    AT+CCLK?

}

String getData() {
    AT+CNUM
}

String setupSMS() {
    AT+CMGF=1
}

String SMSRead() {
    AT+CMGL=5
    AT+CMGR=?
}

String SMSSend() {
    AT+CMGS
}

String SMSsave() {
        AT+CMGW
}

String SMSSendFromStorage() {
        AT+CMSS

}

String SMSMode() {
        AT+CNMI

}

String SMSRestore() {
    AT+CRES

}

String SMSSaveSettings() {
    AT+CSAS
}

String SMSModem() {
    AT+CSCB
}

String SMSSetMOde() {
    AT+CSMP
    AT+CADC?

}

String getLocalTimeStamp() {
AT+CLTS // CHECK
}

String getProviderName() {
    AT+CSPN?
    AT+CCID
    AT+GSV
AT+CROAMING

}

String moduleBehaviour() {
    AT+CCALR
AT+CSMINS?
AT+CMNRP
}

void DTMF() {
    AT+DDET=1,0,0
}

void detectAntenna() {
AT+CANT?

}

String setData() {
    //AT+CTTRING
    // AT+SJDR
    // AT+CMEDPLAY
// AT+CCODE
    // AT+CHF
    // AT+CSCLK
}

String restart() {
CDSCB
}

String timer() {
    AT+CALA
    AT+CALD
}

String powerOff() {
    AT+CPOWD
}

String deleteAllSMS() {
AT+CMGDA
}

String sendToolKitTones() {
    AT+STTONE=?
}

String readEmergencyCommands(){
    Serial.println("AT+CEMNL?");
AT+CEMNL=<
mode>[,<amount
>,<emergency
numbers>
}

String setGSMStatus(int type) {
    Serial.println("AT+GSMBUSY=%d", type); // 1 => enable / 2 => disable / 3 => disable but allow CSD
}

String setupTTL() {
    Serial.println("AT+CTTSPARAM=50,1,50,50,0");
}
String TTL() {
    Serial.println("AT+CTTS=2, Hello");
}

String profileController(String option) {
    switch(option) {
        case "reset":
        Serial.println("AT&D");
        break;
        case "get":
        Serial.println("AT&V");
        break;
        case "set":
        Serial.println("AT&S");
        break;
        default:
        break;
    }
}
