/**
* If not stated otherwise in this file or this component's LICENSE
* file the following copyright and licenses apply:
*
* Copyright 2022 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#include "SmartLink.h"
#include "Log.h"

SmartLink::SmartLink(const string& callsign)
    : _callsign(callsign)
{
    Log("Constructing SamplePlugin link to callsign %s", callsign.c_str());

    uint32_t success = BaseClass::Open(RPC::CommunicationTimeOut, BaseClass::Connector(), callsign);

    if (success != Core::ERROR_NONE) {
        Log("Failed to open link to Thunder with error %s", Core::ErrorToString(success));
    }

    Log("Constructor complete");
}

SmartLink::~SmartLink()
{
    Log("Destructing smart link");

    if (_dictionaryInterface != nullptr) {
        _dictionaryInterface->Release();
        _dictionaryInterface = nullptr;
    }

    BaseClass::Close(Core::infinite);

    Log("Destructor complete");
}

void SmartLink::Operational(const bool upAndRunning)
{
    if (upAndRunning) {
        // Connection is good - lets resolve our interfaces
        if (_dictionaryInterface == nullptr) {
            _dictionaryInterface == BaseClass::Interface();
        }
    } else {
        // Connection is bad, unregister from notifications and release our interfaces
        if (_dictionaryInterface != nullptr) {
            _dictionaryInterface->Release();
            _dictionaryInterface = nullptr;
        }
    }
}