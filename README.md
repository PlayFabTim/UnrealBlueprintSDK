Unreal4.9 Blueprint SDK-Collection for PlayFab README
========


1. Overview:
----
Unreal 4.9 Blueprint SDKs for PlayFab - BETA

The Unreal Blueprint SDK-Collection includes three separate Unreal 4.9 plugins.  You should only install 1 of these plugins in any Unreal project.

* Unreal Client SDK for distribution to End-Users
* Unreal Server SDK for secure machines running sensitive logic
* Unreal Combo SDK for demoing, testing, and special-case circumstances - Typical users will not use this for production code


2. Prerequisites:
----
* Users should be very familiar with the topics covered in our [getting started guide](https://playfab.com/docs/getting-started-with-playfab/).

To connect to the PlayFab service, your machine must be running TLS v1.2 or better.
* For Windows, this means Windows 7 and above
* [Official Microsoft Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa380516%28v=vs.85%29.aspx)
* [Support for SSL/TLS protocols on Windows](http://blogs.msdn.com/b/kaushal/archive/2011/10/02/support-for-ssl-tls-protocols-on-windows.aspx)


3. Setup:
----
For building the game client, distributed to the End-User, you must only use the PlayFabClientSDK.

A game server is not required for all games, however many online games require online server architecture.  PlayFab also does not require you to use the same SDK for client and server.  If your game-server is a separate stand-alone console application, it is possible to use the [C++ WindowsSDK](https://github.com/PlayFab/WindowsSDK).  If your game-server requires an Unreal environment, you can also use the PlayFabServerSDK provided with in the Unreal SDK-Collection.

To implement both client and server in Unreal, you must create two separate projects, and install each plugin separately.


4. Installation:
----
The following instructions apply to each of the three SDKs provided in the Unreal SDK-Collection.

Assumptions

* Windows operating system
* [Microsoft Visual Studio](https://www.visualstudio.com/en-us/products/visual-studio-community-vs.aspx) already installed
* [Unreal Engine](https://www.unrealengine.com/dashboard) already installed

A new project can be built directly from the example project included with each SDK:

* Extract the Unreal SDK package to {UnrealPackageLocation}
* Navigate to {UnrealPackageLocation}/PlayFabClientSDK/ExampleProject
* Right click on ExampleProject.uproject, and "Generate Visual Studio project files" - This process may take several minutes
* Once finished, open {UnrealPackageLocation}/PlayFabClientSDK/ExampleProject/ExampleProject.sln in Visual Studio
* In Visual Studio, "Rebuild Solution" - This process may take several minutes
* You should now be able to create blueprints that utilize PlayFab API calls

Existing Projects:
* Extract the Unreal SDK package to {UnrealPackageLocation}
* Navigate to {UnrealPackageLocation}/PlayFabClientSDK\PluginFiles
* Copy the PlayFab folder into the "Plugins" directory in your existing Unreal project (If the "Plugins" folder does not exist, create it)
* Right click on ExampleProject.uproject, and "Generate Visual Studio project files" - This process may take several minutes
* Once finished, open your *.sln project file with Visual Studio
* In Visual Studio, "Rebuild Solution" - This process may take several minutes
* You should now be able to create blueprints that utilize PlayFab API calls


# Developer Console

The `Developer Console` allows execution of custom commands which can be used to invoke a `CustomEvent` in the `Level Blueprint`.


## UE4 Editor

In the editor the developer console can be opened by pressing the tilda (~) key.


## Android

Make sure that the console is enabled in project settings to use the developer console on Android.

```
Edit->Project Settings->Input->Mobile->Show Console on Four Finger Tap->True
```


# Blueprint Custom Events

Follow the `Blueprint Tutorial` below to populate the `Game Title Id` before invoking the following `Blueprint Custom Events`.


## TestRegister

`TestRegister` is a custom event that registers a user given the `username`, `email`, and `password`.

![00_TestRegisterBlueprint](Images/00_TestRegisterBlueprint.png)

The custom event can be invoked in the console with the following line.

```
ce TestRegister "myUsername" "email@email.com" password
```

On Android, the custom event can be invoked in the console and the command can be entered over `ADB` with the following line.

```
adb shell input text "ce%sTestRegister%s\\""myUsername\\"""%s\\"""email@email.com\\"""%spassword"
```

The output log should print output similar to the following for a success event.

```
Cmd: ce TestRegister "myUsername" "email@email.com" password
LogBlueprintUserMessages: [Test_C_1] Registering User=myUsername Email=email@email.com Password=password
LogPlayFab: Request: {
    "TitleId": "YOUR_GAME_TITLE_ID",
    "Username": "myUsername",
    "Email": "email@email.com",
    "Password": "password",
    "RequireBothUsernameAndEmail": false,
    "DisplayName": null,
    "Origination": null
}
LogPlayFab: Response : {
    "code": 200,
    "status": "OK",
    "data":
    {
        "PlayFabId": "7F10A25FDB140A4C",
        "SessionTicket": "LONG_SESSION_TICKET",
        "Username": "myusername",
        "SettingsForUser":
        {
            "NeedsAttribution": false
        }
    }
}
LogBlueprintUserMessages: [Test_C_1] Register Success:
{"code":200,"status":"OK","data":{"PlayFabId":"7F10A25FDB140A4C",
"SessionTicket":"LONG_SESSION_TICKET",
"Username":"myusername","SettingsForUser":{"NeedsAttribution":false}}}
```


## TestLogin

`TestLogin` is a custom event that will login a user given the corresponding `email` and `password`. A user must be registered before a successful login can occur.

![01_TestLoginBlueprint](Images/01_TestLoginBlueprint.png)

The custom event can be invoked in the console with the following line.

```
ce TestLogin "email@email.com" password
```

On Android, the custom event can be invoked in the console and the command can be entered over `ADB` with the following line.

```
adb shell input text "ce%sTestLogin%s\\""email@email.com\\"""%spassword"
```

The output log should print output similar to the following for a success event.

```
Cmd: ce TestLogin "email@email.com" password
LogPlayFab: Request: {
    "TitleId": "YOUR_GAME_TITLE_ID",
    "Email": "email@email.com",
    "Password": "password"
}
LogPlayFab: Response : {
    "code": 200,
    "status": "OK",
    "data":
    {
        "SessionTicket": "LONG_SESSION_TICKET",
        "PlayFabId": "EDC7CAE0DCB6FA8F",
        "NewlyCreated": false,
        "SettingsForUser":
        {
            "NeedsAttribution": false
        },
        "LastLoginTime": "2016-01-29T02:18:16.692Z"
    }
}
LogBlueprintUserMessages: [Test_C_1] Login Success:
SessionTicket=LONG_SESSION_TICKET PlayFabId=EDC7CAE0DCB6FA8F
```


## GetCloudScriptUrl

`GetCloudScriptUrl` is a custom event that will request a cloud script url given no parameters.

![02_GetCloudScriptUrlBlueprint](Images/02_GetCloudScriptUrlBlueprint.png)

The custom event can be invoked in the console with the following line.

```
ce GetCloudScriptUrl
```

On Android, the custom event can be invoked in the console and the command can be entered over `ADB` with the following line.

```
adb shell input text "ce%sGetCloudScriptUrl"
```

The output log should print output similar to the following for a success event.

```
Cmd: ce GetCloudScriptUrl
LogPlayFab: Request: {
    "Version": 1,
    "Testing": false
}
LogPlayFab: Response : {
    "code": 200,
    "status": "OK",
    "data":
    {
        "Url": "https://YOUR_GAME_TITLE_ID.playfablogic.com/1/prod"
    }
}
LogBlueprintUserMessages: [Test_C_1] GetCloudScriptUrl Success:
Url=https://88E.playfablogic.com/1/prod
```


## TestCloudScript

`GetCloudScriptUrl` is a custom event that will execute cloud script given no parameters. For this test to work, the following custom cloud script must be added to return a success result.

```
handlers.testMe = function(args){  return "Hello World" }
```

![03_TestCloudScriptBlueprint](Images/03_TestCloudScriptBlueprint.png)

The custom event can be invoked in the console with the following line.

```
ce TestCloudScript
```

On Android, the custom event can be invoked in the console and the command can be entered over `ADB` with the following line.

```
adb shell input text "ce%sTestCloudScript"
```

The output log should print output similar to the following for a success event.

```
Cmd: ce TestCloudScript
LogPlayFab: Request: {
    "ActionId": "testMe",
    "Params":
    {
    }
}
LogPlayFab: Response : {
    "code": 200,
    "status": "OK",
    "data":
    {
        "ActionId": "testMe",
        "Version": 1,
        "Revision": 2,
        "Results": "Hello World",
        "ResultsEncoded": "\"Hello World\"",
        "ActionLog": "",
        "ExecutionTime": 0
    }
}
LogJson:Warning: Field Results is of the wrong type.
LogJson:Error: Json Value of type 'Null' used as a 'Object'.
LogBlueprintUserMessages: [Test_C_1] TestCloudScript Success: "Hello World"
```


5. Blueprint Tutorial:
----
The plugin is fairly simple to use. The main things you need to learn are; how to use the provided JSON objects, how to wire up the nodes, and realize that it is extremely simple!

Below are the steps to add an API call node, and manipulate the response JSON object. We will make a simple login with email function that will print out the response JSON object to the screen.

* PlayFab Title setup:
 * You must have a PlayFab account, and you must have created a Title on our website: (https://developer.playfab.com/en-us/studios)
 * Open the Unreal editor by double clicking on the project file.
 * Got to the top bar and select "Blueprints" then "Open Level Blueprint" from the drop down menu.
 * You must tell UnrealSDK about your PlayFab Title
  * In the Level Blueprint, there is a call to SetPlayFabSettings.  Fill in any relevant information including:
  * The TitleId field is mandatory for all api-calls
  * The DevSecretKey is required for all server/admin/matchmaker calls - For security reasons you must never expose this value to players, and neither input nor publish this value into a client build
  * ![TitleId Blueprint](http://api.playfab.com/images/git/ubp_TitleId.png)
* Unreal Setup
 * ![Open Level Blueprint](http://api.playfab.com/images/git/ubp_OpenLevelBP.png)
 * The example project will have some pre-made blueprints that you may use as a template
 * Register and a player, and log in
  * For this we require two api-calls: [RegisterPlayFabUser](https://api.playfab.com/Documentation/Client/method/RegisterPlayFabUser) and [LoginWithEmailAddress](https://api.playfab.com/Documentation/Client/method/LoginWithEmailAddress)
  * Setup the register command:
   * Right click on an empty spot and add an "Add Custom Event Node".
   * Name it "TestRegister"
   * Now add string variables named: "Username", "Email", and "Password" to the custom event.
   * Right click again and search for the "Register PlayFab User" node located in "Play Fab/Client/Authentication".
    * You can also type "register" in the search field to find it quicker.
   * Wire up the event inputs to the RegisterPlayFabUser inputs
   * ![TestRegister Blueprint](http://api.playfab.com/images/git/ubp_TestRegister.png)
  * Setup the login command:
   * Right click on an empty spot and add an "Add Custom Event Node".
   * Name it "TestLogin"
   * Now add string variables named: "Email", and "Password" to the custom event.
   * Right click again and search for the "Login With Email Address" node located in "Play Fab/Client/Authentication".
    * You can also type "login" in the search field to find it quicker.
   * Wire up the event inputs to the RegisterPlayFabUser inputs
  * Both:
   * The response on the node is a JSON object that can be manipulated using the provided JSON functions located in "Play Fab/Json".
   * Drag off from the response node and search for "Encode Json"
   * Now wire the "Encode Json" return up to a "Print String" node. Below is an image of the complete system.
   * ![Login Blueprint](http://api.playfab.com/images/git/ubp_Login.png)
* Now run the project and in the play in editor window hit the tilde ~ key twice. This will bring up the console manager, and make it mostly fullscreen
* The first time you run (only), execute this: *ce TestRegister "myUsername" "email@email.com" password*
* After you register, you can execute this every time you start a client: *ce TestLogin "email@email.com" password*
* Notice you add quotes to email but not to password.
* Once you hit enter you should get the response printed out on the screen.

6. Troubleshooting:
----
If you experience this error:
Plugin 'PlayFab' failed to load because module 'PlayFab' could not be found.  Please ensure the plugin is properly installed, otherwise consider disabling the plugin for this project.

Your Unreal project is not set up to be a C++ project.  Here is a tutorial that will help fix this problem.
http://idkudk.blogspot.com/2015/02/how-to-get-plugins-to-package-correctly.html


General troubleshooting:

For a complete list of available APIs, check out the [online documentation](http://api.playfab.com/Documentation/).

#### Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/hc/en-us)


7. Acknowledgements
----
The PlayFab UnrealBlueprintSDK and the Blueprint Tutorial in this document were built by [Joshua Lyons](https://github.com/JLyons1985), and submitted to PlayFab October, 2015


8. Copyright and Licensing Information:
----
  Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.

