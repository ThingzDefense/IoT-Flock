/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2019 IRIL Lab, KICS, UET Lahore <iril@kics.edu.pk>       *
 *                                                                         *
 *  This file is part of IRIL Advanced Data Generator.                     *                                         *
 *                                                                         *
 *  IRIL Advanced Data Generator is free software: you can redistribute    *
 *  it and/or modify it under the terms of the GNU General Public License  *
 *  as published by the Free Software Foundation, version 3 of the License.*
 *                                                                         *
 *                                                                         *
 *  IRIL Advanced Data Generator is distributed in the hope that it will   *
 *  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty *
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the        *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with IRIL Advanced Data Generator.                               *
 *  If not, see <http://www.gnu.org/licenses/>.                            *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef OBJGLOBAL_H
#define OBJGLOBAL_H
#include<qstring.h>

class objGlobal
{
public:
    QString msg_DeviceCreated = "Device Created";
    QString msg_Connecting = "Connecting...";
    QString msg_Connected = "Connected";
    QString msg_Disconnected = "Disconnected";
    QString msg_ErrorInSubscribing = "Error in subscribing";
    QString msg_Subscribed = "Topic Subscribed:";
    QString msg_ErrorInPublishing = "Error in publishing";
    QString msg_SuccessfulPublished = "Published =";
    QString msg_CoapResponseError = "Coap Response Error:";
    QString msg_CoapResponse = "Coap Response Received:";
    QString msg_CoapGetRequest = "Coap Get Request:";
    QString msg_CoapPOSTRequest = "Coap Post Request:";
    QString msg_CoapPUTRequest = "Coap Put Request:";
    QString msg_CoapDELETERequest = "Coap Delete Request:";
    QString msg_CoapOBSERVERequest = "Coap Observe Request:";
    //QString msg_DeviceCreated = "Device Created";


};

#endif // OBJGLOBAL_H
