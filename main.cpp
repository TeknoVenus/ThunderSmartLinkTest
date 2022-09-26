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

#include "Log.h"
#include "Module.h"

using namespace WPEFramework;

int main(int argc, char const* argv[])
{
    {
        Log("Sample JSON-RPC Test App");
        Core::SystemInfo::SetEnvironment(_T("THUNDER_ACCESS"), (_T("127.0.0.1:55555")));

        JSONRPC::SmartLinkType<Core::JSON::IElement> remoteObject(_T("Controller.1"), _T("client.jsonrpc.2"));
    }

    Core::Singleton::Dispose();

    return EXIT_SUCCESS;
}
