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

#pragma once

#include "Module.h"
#include <interfaces/IDictionary.h>

using namespace WPEFramework;

using BaseClass = RPC::SmartInterfaceType<Exchange::IDictionary>;

/**
 * @brief Connection to the Sample Plugin over COM-RPC
 *
 * Acts as a convenience library over the COM-RPC connection to make it easy for clients
 * to register for notifications and other useful events
 *
 * Uses the SmartLink which can automatically handle disconnections and plugin
 * failures for us!
 */
class SmartLink : public BaseClass {

public:
    SmartLink(const string& callsign);
    ~SmartLink() override;

    SmartLink(const SmartLink&) = delete;
    SmartLink& operator=(const SmartLink&) = delete;

    // Run our own code when the operational status of the plugin changes
    void Operational(const bool upAndRunning) override;

private:
    const string _callsign;
    Exchange::IDictionary* _dictionaryInterface;
};