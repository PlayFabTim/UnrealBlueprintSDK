//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Client
// SDK Version: 0.0.160125
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabClientAPI.h"

UPlayFabClientAPI* Client_proxy = NULL;

UPlayFabClientAPI::UPlayFabClientAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    Client_proxy = this;
}

void UPlayFabClientAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabClientAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabClientAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Client API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////
/** Gets a Photon custom authentication token that can be used to securely join the player into a Photon room. See https://api.playfab.com/docs/using-photon-with-playfab/ for more details. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPhotonAuthenticationToken(FClientGetPhotonAuthenticationTokenRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPhotonAuthenticationToken";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PhotonApplicationId.IsEmpty() || request.PhotonApplicationId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PhotonApplicationId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PhotonApplicationId"), request.PhotonApplicationId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using the Android device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithAndroidDeviceID(FClientLoginWithAndroidDeviceIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithAndroidDeviceID";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.AndroidDevice.IsEmpty() || request.AndroidDevice == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDevice"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), request.AndroidDevice);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using a custom unique identifier generated by the title, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithCustomID(FClientLoginWithCustomIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithCustomID";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.CustomId.IsEmpty() || request.CustomId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithEmailAddress(FClientLoginWithEmailAddressRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithEmailAddress";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

UPlayFabClientAPI* UPlayFabClientAPI::PlayFabLoginWithEmailAddress(FString email, FString password,
	FDelegateOnSuccessLoginWithEmailAddress onSuccess,
	FDelegateOnFailureLoginWithEmailAddress onFailure)
{
	// Objects containing request data
	UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
	UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

	manager->OnSuccessLoginWithEmailAddress = onSuccess;
	manager->OnFailureLoginWithEmailAddress = onFailure;
	manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabClientAPI::HelperLoginWithEmailAddress);

	// Setup the request
	manager->PlayFabRequestURL = "/Client/LoginWithEmailAddress";
	manager->useSessionTicket = false;
	manager->isLoginRequest = true;

	// Setup request object
	OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
	if (email.IsEmpty() || email == "")
	{
		OutRestJsonObj->SetFieldNull(TEXT("Email"));
	}
	else
	{
		OutRestJsonObj->SetStringField(TEXT("Email"), email);
	}

	if (password.IsEmpty() || password == "")
	{
		OutRestJsonObj->SetFieldNull(TEXT("Password"));
	}
	else
	{
		OutRestJsonObj->SetStringField(TEXT("Password"), password);
	}

	// Add Request to manager
	manager->SetRequestObject(OutRestJsonObj);

	manager->GetResponseObject();

	return manager;
}

// LoginWithEmailAddress has been invoked, now there's a response
void UPlayFabClientAPI::HelperLoginWithEmailAddress(FPlayFabBaseModel response, bool successful)
{
	FPlayFabError error = response.responseError;
	if (error.hasError)
	{
		if (OnFailureLoginWithEmailAddress.IsBound())
		{
			OnFailureLoginWithEmailAddress.Execute(
				error.ErrorCode,
				error.ErrorName.IsEmpty() ? "" : error.ErrorName,
				error.ErrorMessage.IsEmpty() ? "" : error.ErrorMessage,
				error.ErrorDetails.IsEmpty() ? "" : error.ErrorDetails);
		}
	}
	else
	{
		FClientLoginResult result = UPlayFabClientModelDecoder::decodeLoginResultResponse(response.responseData);
		if (OnSuccessLoginWithEmailAddress.IsBound())
		{
			OnSuccessLoginWithEmailAddress.Execute(result.SessionTicket,
				result.PlayFabId);
		}
	}
}

/** Signs the user in using a Facebook access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithFacebook(FClientLoginWithFacebookRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithFacebook";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using an iOS Game Center player identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithGameCenter(FClientLoginWithGameCenterRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithGameCenter";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.PlayerId.IsEmpty() || request.PlayerId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayerId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayerId"), request.PlayerId);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using a Google account access token, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithGoogleAccount(FClientLoginWithGoogleAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithGoogleAccount";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);
    if (request.PublisherId.IsEmpty() || request.PublisherId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PublisherId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PublisherId"), request.PublisherId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using the vendor-specific iOS device identifier, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithIOSDeviceID(FClientLoginWithIOSDeviceIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithIOSDeviceID";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.DeviceId.IsEmpty() || request.DeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.DeviceModel.IsEmpty() || request.DeviceModel == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceModel"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceModel"), request.DeviceModel);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using a Kongregate player account. */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithKongregate(FClientLoginWithKongregateRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithKongregate";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.KongregateId.IsEmpty() || request.KongregateId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("KongregateId"), request.KongregateId);
    }

    if (request.AuthTicket.IsEmpty() || request.AuthTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthTicket"), request.AuthTicket);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithPlayFab(FClientLoginWithPlayFabRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithPlayFab";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using a PlayStation Network authentication code, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithPSN(FClientLoginWithPSNRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithPSN";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.AuthCode.IsEmpty() || request.AuthCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthCode"), request.AuthCode);
    }

    if (request.RedirectUri.IsEmpty() || request.RedirectUri == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("RedirectUri"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("RedirectUri"), request.RedirectUri);
    }

    OutRestJsonObj->SetNumberField(TEXT("IssuerId"), request.IssuerId);
    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using a Steam authentication ticket, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithSteam(FClientLoginWithSteamRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithSteam";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.SteamTicket.IsEmpty() || request.SteamTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SteamTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SteamTicket"), request.SteamTicket);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Signs the user in using a Xbox Live Token, returning a session identifier that can subsequently be used for API calls which require an authenticated user */
UPlayFabClientAPI* UPlayFabClientAPI::LoginWithXbox(FClientLoginWithXboxRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LoginWithXbox";
    manager->useSessionTicket = false;
    manager->isLoginRequest = true;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.XboxToken.IsEmpty() || request.XboxToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("XboxToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("XboxToken"), request.XboxToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("CreateAccount"), request.CreateAccount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Registers a new Playfab user account, returning a session identifier that can subsequently be used for API calls which require an authenticated user. You must supply either a username or an email address. */
UPlayFabClientAPI* UPlayFabClientAPI::RegisterPlayFabUser(FClientRegisterPlayFabUserRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RegisterPlayFabUser";
    manager->useSessionTicket = false;


    // Setup request object
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }

    OutRestJsonObj->SetBoolField(TEXT("RequireBothUsernameAndEmail"), request.RequireBothUsernameAndEmail);
    if (request.DisplayName.IsEmpty() || request.DisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DisplayName"), request.DisplayName);
    }

    if (request.Origination.IsEmpty() || request.Origination == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Origination"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Origination"), request.Origination);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Adds playfab username/password auth to an existing semi-anonymous account created via a 3rd party auth method. */
UPlayFabClientAPI* UPlayFabClientAPI::AddUsernamePassword(FClientAddUsernamePasswordRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddUsernamePassword";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.Password.IsEmpty() || request.Password == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Password"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Password"), request.Password);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the user's PlayFab account details */
UPlayFabClientAPI* UPlayFabClientAPI::GetAccountInfo(FClientGetAccountInfoRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetAccountInfo";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.TitleDisplayName.IsEmpty() || request.TitleDisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TitleDisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), request.TitleDisplayName);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(FClientGetPlayFabIDsFromFacebookIDsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromFacebookIDs";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.FacebookIDs.IsEmpty() || request.FacebookIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FacebookIDs"));
    }
    else
    {
        TArray<FString> FacebookIDsArray;
        FString(request.FacebookIDs).ParseIntoArray(FacebookIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FacebookIDs"), FacebookIDsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of Game Center identifiers (referenced in the Game Center Programming Guide as the Player Identifier). */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(FClientGetPlayFabIDsFromGameCenterIDsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromGameCenterIDs";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.GameCenterIDs.IsEmpty() || request.GameCenterIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameCenterIDs"));
    }
    else
    {
        TArray<FString> GameCenterIDsArray;
        FString(request.GameCenterIDs).ParseIntoArray(GameCenterIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("GameCenterIDs"), GameCenterIDsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of Google identifiers. The Google identifiers are the IDs for the user accounts, available as "id" in the Google+ People API calls. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(FClientGetPlayFabIDsFromGoogleIDsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromGoogleIDs";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.GoogleIDs.IsEmpty() || request.GoogleIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GoogleIDs"));
    }
    else
    {
        TArray<FString> GoogleIDsArray;
        FString(request.GoogleIDs).ParseIntoArray(GoogleIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("GoogleIDs"), GoogleIDsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of Kongregate identifiers. The Kongregate identifiers are the IDs for the user accounts, available as "user_id" from the Kongregate API methods(ex: http://developers.kongregate.com/docs/client/getUserId). */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(FClientGetPlayFabIDsFromKongregateIDsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromKongregateIDs";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.KongregateIDs.IsEmpty() || request.KongregateIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateIDs"));
    }
    else
    {
        TArray<FString> KongregateIDsArray;
        FString(request.KongregateIDs).ParseIntoArray(KongregateIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KongregateIDs"), KongregateIDsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromPSNAccountIDs(FClientGetPlayFabIDsFromPSNAccountIDsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromPSNAccountIDs";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.PSNAccountIDs.IsEmpty() || request.PSNAccountIDs == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PSNAccountIDs"));
    }
    else
    {
        TArray<FString> PSNAccountIDsArray;
        FString(request.PSNAccountIDs).ParseIntoArray(PSNAccountIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PSNAccountIDs"), PSNAccountIDsArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IssuerId"), request.IssuerId);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayFabIDsFromSteamIDs(FClientGetPlayFabIDsFromSteamIDsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayFabIDsFromSteamIDs";
    manager->useSessionTicket = true;


    // Setup request object
    // Copy int array to float
    TArray<float> tempArray;
    for (int32 i = 0; i < request.SteamIDs.Num(); ++i)
    {
        tempArray.Add(float(request.SteamIDs[i]));
    }
    OutRestJsonObj->SetNumberArrayField(TEXT("SteamIDs"), tempArray);



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves all requested data for a user in one unified request. By default, this API returns all  data for the locally signed-in user. The input parameters may be used to limit the data retrieved to any subset of the available data, as well as retrieve the available data for a different user. Note that certain data, including inventory, virtual currency balances, and personally identifying information, may only be retrieved for the locally signed-in user. In the example below, a request is made for the account details, virtual currency balances, and specified user data for the locally signed-in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserCombinedInfo(FClientGetUserCombinedInfoRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserCombinedInfo";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.Username.IsEmpty() || request.Username == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }

    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    if (request.TitleDisplayName.IsEmpty() || request.TitleDisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TitleDisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), request.TitleDisplayName);
    }

    OutRestJsonObj->SetBoolField(TEXT("GetAccountInfo"), request.GetAccountInfo);
    OutRestJsonObj->SetBoolField(TEXT("GetInventory"), request.GetInventory);
    OutRestJsonObj->SetBoolField(TEXT("GetVirtualCurrency"), request.GetVirtualCurrency);
    OutRestJsonObj->SetBoolField(TEXT("GetUserData"), request.GetUserData);
    // Check to see if string is empty
    if (request.UserDataKeys.IsEmpty() || request.UserDataKeys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("UserDataKeys"));
    }
    else
    {
        TArray<FString> UserDataKeysArray;
        FString(request.UserDataKeys).ParseIntoArray(UserDataKeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("UserDataKeys"), UserDataKeysArray);
    }

    OutRestJsonObj->SetBoolField(TEXT("GetReadOnlyData"), request.GetReadOnlyData);
    // Check to see if string is empty
    if (request.ReadOnlyDataKeys.IsEmpty() || request.ReadOnlyDataKeys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReadOnlyDataKeys"));
    }
    else
    {
        TArray<FString> ReadOnlyDataKeysArray;
        FString(request.ReadOnlyDataKeys).ParseIntoArray(ReadOnlyDataKeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ReadOnlyDataKeys"), ReadOnlyDataKeysArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the Android device identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkAndroidDeviceID(FClientLinkAndroidDeviceIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkAndroidDeviceID";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.AndroidDevice.IsEmpty() || request.AndroidDevice == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDevice"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDevice"), request.AndroidDevice);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the custom identifier, generated by the title, to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkCustomID(FClientLinkCustomIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkCustomID";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CustomId.IsEmpty() || request.CustomId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the Facebook account associated with the provided Facebook access token to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkFacebookAccount(FClientLinkFacebookAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkFacebookAccount";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("ForceLink"), request.ForceLink);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the Game Center account associated with the provided Game Center ID to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkGameCenterAccount(FClientLinkGameCenterAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkGameCenterAccount";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.GameCenterId.IsEmpty() || request.GameCenterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameCenterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameCenterId"), request.GameCenterId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the currently signed-in user account to the Google account specified by the Google account access token */
UPlayFabClientAPI* UPlayFabClientAPI::LinkGoogleAccount(FClientLinkGoogleAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkGoogleAccount";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.AccessToken.IsEmpty() || request.AccessToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AccessToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AccessToken"), request.AccessToken);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the vendor-specific iOS device identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkIOSDeviceID(FClientLinkIOSDeviceIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkIOSDeviceID";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.DeviceId.IsEmpty() || request.DeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }

    if (request.OS.IsEmpty() || request.OS == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OS"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OS"), request.OS);
    }

    if (request.DeviceModel.IsEmpty() || request.DeviceModel == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceModel"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceModel"), request.DeviceModel);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the Kongregate identifier to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkKongregate(FClientLinkKongregateAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkKongregate";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.KongregateId.IsEmpty() || request.KongregateId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KongregateId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("KongregateId"), request.KongregateId);
    }

    if (request.AuthTicket.IsEmpty() || request.AuthTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthTicket"), request.AuthTicket);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the PlayStation Network account associated with the provided access code to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkPSNAccount(FClientLinkPSNAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkPSNAccount";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.AuthCode.IsEmpty() || request.AuthCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthCode"), request.AuthCode);
    }

    if (request.RedirectUri.IsEmpty() || request.RedirectUri == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("RedirectUri"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("RedirectUri"), request.RedirectUri);
    }

    OutRestJsonObj->SetNumberField(TEXT("IssuerId"), request.IssuerId);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the Steam account associated with the provided Steam authentication ticket to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkSteamAccount(FClientLinkSteamAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkSteamAccount";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.SteamTicket.IsEmpty() || request.SteamTicket == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SteamTicket"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SteamTicket"), request.SteamTicket);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Links the Xbox Live account associated with the provided access code to the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::LinkXboxAccount(FClientLinkXboxAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LinkXboxAccount";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.XboxToken.IsEmpty() || request.XboxToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("XboxToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("XboxToken"), request.XboxToken);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Forces an email to be sent to the registered email address for the user's account, with a link allowing the user to change the password */
UPlayFabClientAPI* UPlayFabClientAPI::SendAccountRecoveryEmail(FClientSendAccountRecoveryEmailRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SendAccountRecoveryEmail";
    manager->useSessionTicket = false;


    // Setup request object
    if (request.Email.IsEmpty() || request.Email == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());
    if (request.PublisherId.IsEmpty() || request.PublisherId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PublisherId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PublisherId"), request.PublisherId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related Android device identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkAndroidDeviceID(FClientUnlinkAndroidDeviceIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkAndroidDeviceID";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.AndroidDeviceId.IsEmpty() || request.AndroidDeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AndroidDeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AndroidDeviceId"), request.AndroidDeviceId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related custom identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkCustomID(FClientUnlinkCustomIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkCustomID";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CustomId.IsEmpty() || request.CustomId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomId"), request.CustomId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related Facebook account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkFacebookAccount(FClientUnlinkFacebookAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkFacebookAccount";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related Game Center account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkGameCenterAccount(FClientUnlinkGameCenterAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkGameCenterAccount";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related Google account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkGoogleAccount(FClientUnlinkGoogleAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkGoogleAccount";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related iOS device identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkIOSDeviceID(FClientUnlinkIOSDeviceIDRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkIOSDeviceID";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.DeviceId.IsEmpty() || request.DeviceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceId"), request.DeviceId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related Kongregate identifier from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkKongregate(FClientUnlinkKongregateAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkKongregate";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related PSN account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkPSNAccount(FClientUnlinkPSNAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkPSNAccount";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related Steam account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkSteamAccount(FClientUnlinkSteamAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkSteamAccount";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlinks the related Xbox Live account from the user's PlayFab account */
UPlayFabClientAPI* UPlayFabClientAPI::UnlinkXboxAccount(FClientUnlinkXboxAccountRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlinkXboxAccount";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.XboxToken.IsEmpty() || request.XboxToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("XboxToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("XboxToken"), request.XboxToken);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the title specific display name for the user */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserTitleDisplayName(FClientUpdateUserTitleDisplayNameRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserTitleDisplayName";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.DisplayName.IsEmpty() || request.DisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DisplayName"), request.DisplayName);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Retrieves a list of ranked friends of the current player for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboard(FClientGetFriendLeaderboardRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboard";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of ranked friends of the current player for the given statistic, centered on the currently signed-in user */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboardAroundCurrentUser(FClientGetFriendLeaderboardAroundCurrentUserRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboardAroundCurrentUser";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of ranked friends of the current player for the given statistic, centered on the requested PlayFab user. If PlayFabId is empty or null will return currently logged in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendLeaderboardAroundPlayer(FClientGetFriendLeaderboardAroundPlayerRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendLeaderboardAroundPlayer";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboard(FClientGetLeaderboardRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboard";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundCurrentUser(FClientGetLeaderboardAroundCurrentUserRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundCurrentUser";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of ranked users for the given statistic, centered on the requested player. If PlayFabId is empty or null will return currently logged in user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundPlayer(FClientGetLeaderboardAroundPlayerRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundPlayer";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserData(FClientGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserData";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserPublisherData(FClientGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserPublisherData";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserPublisherReadOnlyData(FClientGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserPublisherReadOnlyData";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserReadOnlyData(FClientGetUserDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserReadOnlyData";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the details of all title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserStatistics(FClientGetUserStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserStatistics";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Creates and updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserData(FClientUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserData";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Creates and updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserPublisherData(FClientUpdateUserDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserPublisherData";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the values of the specified title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateUserStatistics(FClientUpdateUserStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateUserStatistics";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.UserStatistics != NULL) OutRestJsonObj->SetObjectField(TEXT("UserStatistics"), request.UserStatistics);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabClientAPI* UPlayFabClientAPI::GetCatalogItems(FClientGetCatalogItemsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCatalogItems";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the set of items defined for the specified store, including all prices defined */
UPlayFabClientAPI* UPlayFabClientAPI::GetStoreItems(FClientGetStoreItemsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetStoreItems";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StoreId.IsEmpty() || request.StoreId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the key-value store of custom title settings */
UPlayFabClientAPI* UPlayFabClientAPI::GetTitleData(FClientGetTitleDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTitleData";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the title news feed, as configured in the developer portal */
UPlayFabClientAPI* UPlayFabClientAPI::GetTitleNews(FClientGetTitleNewsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTitleNews";
    manager->useSessionTicket = true;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments the user's balance of the specified virtual currency by the stated amount */
UPlayFabClientAPI* UPlayFabClientAPI::AddUserVirtualCurrency(FClientAddUserVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddUserVirtualCurrency";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Confirms with the payment provider that the purchase was approved (if applicable) and adjusts inventory and virtual currency balances as appropriate */
UPlayFabClientAPI* UPlayFabClientAPI::ConfirmPurchase(FClientConfirmPurchaseRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ConfirmPurchase";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.OrderId.IsEmpty() || request.OrderId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
UPlayFabClientAPI* UPlayFabClientAPI::ConsumeItem(FClientConsumeItemRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ConsumeItem";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    OutRestJsonObj->SetNumberField(TEXT("ConsumeCount"), request.ConsumeCount);
    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the specified character's current inventory of virtual goods */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterInventory(FClientGetCharacterInventoryRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterInventory";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a completed purchase along with its current PlayFab status. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPurchase(FClientGetPurchaseRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPurchase";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.OrderId.IsEmpty() || request.OrderId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the user's current inventory of virtual goods */
UPlayFabClientAPI* UPlayFabClientAPI::GetUserInventory(FClientGetUserInventoryRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetUserInventory";
    manager->useSessionTicket = true;


    // Setup request object


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Selects a payment option for purchase order created via StartPurchase */
UPlayFabClientAPI* UPlayFabClientAPI::PayForPurchase(FClientPayForPurchaseRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/PayForPurchase";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.OrderId.IsEmpty() || request.OrderId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }

    if (request.ProviderName.IsEmpty() || request.ProviderName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ProviderName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ProviderName"), request.ProviderName);
    }

    if (request.Currency.IsEmpty() || request.Currency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Currency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Currency"), request.Currency);
    }

    if (request.ProviderTransactionId.IsEmpty() || request.ProviderTransactionId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ProviderTransactionId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ProviderTransactionId"), request.ProviderTransactionId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Buys a single item with virtual currency. You must specify both the virtual currency to use to purchase, as well as what the client believes the price to be. This lets the server fail the purchase if the price has changed. */
UPlayFabClientAPI* UPlayFabClientAPI::PurchaseItem(FClientPurchaseItemRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/PurchaseItem";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ItemId.IsEmpty() || request.ItemId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }

    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Price"), request.Price);
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.StoreId.IsEmpty() || request.StoreId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Promotions->Coupons tab in the PlayFab Game Manager. See this post for more information on coupons:  https://playfab.com/blog/using-stores-and-coupons-game-manager/ */
UPlayFabClientAPI* UPlayFabClientAPI::RedeemCoupon(FClientRedeemCouponRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RedeemCoupon";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CouponCode.IsEmpty() || request.CouponCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CouponCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CouponCode"), request.CouponCode);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Submit a report for another player (due to bad bahavior, etc.), so that customer service representatives for the title can take action concerning potentially toxic players. */
UPlayFabClientAPI* UPlayFabClientAPI::ReportPlayer(FClientReportPlayerClientRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ReportPlayer";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ReporteeId.IsEmpty() || request.ReporteeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReporteeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReporteeId"), request.ReporteeId);
    }

    if (request.Comment.IsEmpty() || request.Comment == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Comment"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Comment"), request.Comment);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Creates an order for a list of items from the title catalog */
UPlayFabClientAPI* UPlayFabClientAPI::StartPurchase(FClientStartPurchaseRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/StartPurchase";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.StoreId.IsEmpty() || request.StoreId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    OutRestJsonObj->SetObjectArrayField(TEXT("Items"), request.Items);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Decrements the user's balance of the specified virtual currency by the stated amount */
UPlayFabClientAPI* UPlayFabClientAPI::SubtractUserVirtualCurrency(FClientSubtractUserVirtualCurrencyRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SubtractUserVirtualCurrency";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }

    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Unlocks a container item in the user's inventory and consumes a key item of the type indicated by the container item */
UPlayFabClientAPI* UPlayFabClientAPI::UnlockContainerItem(FClientUnlockContainerItemRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UnlockContainerItem";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ContainerItemId.IsEmpty() || request.ContainerItemId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerItemId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ContainerItemId"), request.ContainerItemId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////
/** Adds the PlayFab user, based upon a match against a supplied unique identifier, to the friend list of the local user. At least one of FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName should be initialized. */
UPlayFabClientAPI* UPlayFabClientAPI::AddFriend(FClientAddFriendRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddFriend";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }

    if (request.FriendUsername.IsEmpty() || request.FriendUsername == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendUsername"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendUsername"), request.FriendUsername);
    }

    if (request.FriendEmail.IsEmpty() || request.FriendEmail == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendEmail"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendEmail"), request.FriendEmail);
    }

    if (request.FriendTitleDisplayName.IsEmpty() || request.FriendTitleDisplayName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendTitleDisplayName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendTitleDisplayName"), request.FriendTitleDisplayName);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the current friend list for the local user, constrained to users who have PlayFab accounts. Friends from linked accounts (Facebook, Steam) are also included. You may optionally exclude some linked services' friends. */
UPlayFabClientAPI* UPlayFabClientAPI::GetFriendsList(FClientGetFriendsListRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetFriendsList";
    manager->useSessionTicket = true;


    // Setup request object
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Removes a specified user from the friend list of the local user */
UPlayFabClientAPI* UPlayFabClientAPI::RemoveFriend(FClientRemoveFriendRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RemoveFriend";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the tag list for a specified user in the friend list of the local user */
UPlayFabClientAPI* UPlayFabClientAPI::SetFriendTags(FClientSetFriendTagsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/SetFriendTags";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }

    // Check to see if string is empty
    if (request.Tags.IsEmpty() || request.Tags == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Tags"));
    }
    else
    {
        TArray<FString> TagsArray;
        FString(request.Tags).ParseIntoArray(TagsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Tags"), TagsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// IOS-Specific APIs
//////////////////////////////////////////////////////
/** Registers the iOS device to receive push notifications */
UPlayFabClientAPI* UPlayFabClientAPI::RegisterForIOSPushNotification(FClientRegisterForIOSPushNotificationRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RegisterForIOSPushNotification";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.DeviceToken.IsEmpty() || request.DeviceToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceToken"), request.DeviceToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), request.SendPushNotificationConfirmation);
    if (request.ConfirmationMessage.IsEmpty() || request.ConfirmationMessage == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ConfirmationMessage"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ConfirmationMessage"), request.ConfirmationMessage);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Restores all in-app purchases based on the given refresh receipt. */
UPlayFabClientAPI* UPlayFabClientAPI::RestoreIOSPurchases(FClientRestoreIOSPurchasesRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RestoreIOSPurchases";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ReceiptData.IsEmpty() || request.ReceiptData == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptData"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptData"), request.ReceiptData);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Validates with the Apple store that the receipt for an iOS in-app purchase is valid and that it matches the purchased catalog item */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateIOSReceipt(FClientValidateIOSReceiptRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateIOSReceipt";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ReceiptData.IsEmpty() || request.ReceiptData == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptData"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptData"), request.ReceiptData);
    }

    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }

    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Matchmaking APIs
//////////////////////////////////////////////////////
/** Get details about all current running game servers matching the given parameters. */
UPlayFabClientAPI* UPlayFabClientAPI::GetCurrentGames(FClientCurrentGamesRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCurrentGames";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.Region.IsEmpty() || request.Region == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }

    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    if (request.GameMode.IsEmpty() || request.GameMode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/**  Get details about the regions hosting game servers matching the given parameters. */
UPlayFabClientAPI* UPlayFabClientAPI::GetGameServerRegions(FClientGameServerRegionsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetGameServerRegions";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Attempts to locate a game session matching the given parameters. If the goal is to match the player into a specific active session, only the LobbyId is required. Otherwise, the BuildVersion, GameMode, and Region are all required parameters. Note that parameters specified in the search are required (they are not weighting factors). If a slot is found in a server instance matching the parameters, the slot will be assigned to that player, removing it from the availabe set. In that case, the information on the game session will be returned, otherwise the Status returned will be GameNotFound. Note that EnableQueue is deprecated at this time. */
UPlayFabClientAPI* UPlayFabClientAPI::Matchmake(FClientMatchmakeRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/Matchmake";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    if (request.Region.IsEmpty() || request.Region == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }

    if (request.GameMode.IsEmpty() || request.GameMode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }

    if (request.LobbyId.IsEmpty() || request.LobbyId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    OutRestJsonObj->SetBoolField(TEXT("EnableQueue"), request.EnableQueue);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Start a new game server with a given configuration, add the current player and return the connection information. */
UPlayFabClientAPI* UPlayFabClientAPI::StartGame(FClientStartGameRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/StartGame";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    if (request.Region.IsEmpty() || request.Region == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Region"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Region"), request.Region);
    }

    if (request.GameMode.IsEmpty() || request.GameMode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CustomCommandLineData.IsEmpty() || request.CustomCommandLineData == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CustomCommandLineData"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CustomCommandLineData"), request.CustomCommandLineData);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Android-Specific APIs
//////////////////////////////////////////////////////
/** Registers the Android device to receive push notifications */
UPlayFabClientAPI* UPlayFabClientAPI::AndroidDevicePushNotificationRegistration(FClientAndroidDevicePushNotificationRegistrationRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AndroidDevicePushNotificationRegistration";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.DeviceToken.IsEmpty() || request.DeviceToken == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("DeviceToken"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("DeviceToken"), request.DeviceToken);
    }

    OutRestJsonObj->SetBoolField(TEXT("SendPushNotificationConfirmation"), request.SendPushNotificationConfirmation);
    if (request.ConfirmationMessege.IsEmpty() || request.ConfirmationMessege == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ConfirmationMessege"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ConfirmationMessege"), request.ConfirmationMessege);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Validates a Google Play purchase and gives the corresponding item to the player. */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateGooglePlayPurchase(FClientValidateGooglePlayPurchaseRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateGooglePlayPurchase";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ReceiptJson.IsEmpty() || request.ReceiptJson == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptJson"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptJson"), request.ReceiptJson);
    }

    if (request.Signature.IsEmpty() || request.Signature == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Signature"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Signature"), request.Signature);
    }

    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }

    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////
/** Logs a custom analytics event */
UPlayFabClientAPI* UPlayFabClientAPI::LogEvent(FClientLogEventRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/LogEvent";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.Timestamp.IsEmpty() || request.Timestamp == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }

    if (request.EventName.IsEmpty() || request.EventName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }

    if (request.Body != NULL) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);
    OutRestJsonObj->SetBoolField(TEXT("ProfileSetEvent"), request.ProfileSetEvent);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Adds users to the set of those able to update both the shared data, as well as the set of users in the group. Only users in the group can add new members. */
UPlayFabClientAPI* UPlayFabClientAPI::AddSharedGroupMembers(FClientAddSharedGroupMembersRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AddSharedGroupMembers";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    }
    else
    {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Requests the creation of a shared group object, containing key/value pairs which may be updated by all members of the group. Upon creation, the current user will be the only member of the group. */
UPlayFabClientAPI* UPlayFabClientAPI::CreateSharedGroup(FClientCreateSharedGroupRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/CreateSharedGroup";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the key-value store of custom publisher settings */
UPlayFabClientAPI* UPlayFabClientAPI::GetPublisherData(FClientGetPublisherDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPublisherData";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves data stored in a shared group object, as well as the list of members in the group. Non-members of the group may use this to retrieve group data, including membership, but they will not receive data for keys marked as private. */
UPlayFabClientAPI* UPlayFabClientAPI::GetSharedGroupData(FClientGetSharedGroupDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetSharedGroupData";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetBoolField(TEXT("GetMembers"), request.GetMembers);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. */
UPlayFabClientAPI* UPlayFabClientAPI::RemoveSharedGroupMembers(FClientRemoveSharedGroupMembersRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RemoveSharedGroupMembers";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    }
    else
    {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group can update the data. */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateSharedGroupData(FClientUpdateSharedGroupDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateSharedGroupData";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Sony-specific APIs
//////////////////////////////////////////////////////
/** Checks for any new consumable entitlements. If any are found, they are consumed and added as PlayFab items */
UPlayFabClientAPI* UPlayFabClientAPI::ConsumePSNEntitlements(FClientConsumePSNEntitlementsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ConsumePSNEntitlements";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    OutRestJsonObj->SetNumberField(TEXT("ServiceLabel"), request.ServiceLabel);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Uses the supplied OAuth code to refresh the internally cached player PSN auth token */
UPlayFabClientAPI* UPlayFabClientAPI::RefreshPSNAuthToken(FClientRefreshPSNAuthTokenRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RefreshPSNAuthToken";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.AuthCode.IsEmpty() || request.AuthCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AuthCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("AuthCode"), request.AuthCode);
    }

    if (request.RedirectUri.IsEmpty() || request.RedirectUri == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("RedirectUri"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("RedirectUri"), request.RedirectUri);
    }

    OutRestJsonObj->SetNumberField(TEXT("IssuerId"), request.IssuerId);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Retrieves the title-specific URL for Cloud Script servers. This must be queried once, prior  to making any calls to RunCloudScript. */
UPlayFabClientAPI* UPlayFabClientAPI::GetCloudScriptUrl(FClientGetCloudScriptUrlRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCloudScriptUrl";
    manager->useSessionTicket = true;


    // Setup request object
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("Testing"), request.Testing);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Triggers a particular server action, passing the provided inputs to the hosted Cloud Script. An action in this context is a handler in the JavaScript. NOTE: Before calling this API, you must call GetCloudScriptUrl to be assigned a Cloud Script server URL. When using an official PlayFab SDK, this URL is stored internally in the SDK, but GetCloudScriptUrl must still be manually called. */
UPlayFabClientAPI* UPlayFabClientAPI::RunCloudScript(FClientRunCloudScriptRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/RunCloudScript";
    manager->useSessionTicket = true;
    manager->cloudScript = true;


    // Setup request object
    if (request.ActionId.IsEmpty() || request.ActionId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ActionId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ActionId"), request.ActionId);
    }

    if (request.Params != NULL) OutRestJsonObj->SetObjectField(TEXT("Params"), request.Params);
    if (request.ParamsEncoded != "") OutRestJsonObj->SetStringField(TEXT("ParamsEncoded"), request.ParamsEncoded);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://support.playfab.com/support/discussions/topics/1000059929 */
UPlayFabClientAPI* UPlayFabClientAPI::GetContentDownloadUrl(FClientGetContentDownloadUrlRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetContentDownloadUrl";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.Key.IsEmpty() || request.Key == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }

    if (request.HttpMethod.IsEmpty() || request.HttpMethod == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("HttpMethod"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("HttpMethod"), request.HttpMethod);
    }

    OutRestJsonObj->SetBoolField(TEXT("ThruCDN"), request.ThruCDN);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Lists all of the characters that belong to a specific user. */
UPlayFabClientAPI* UPlayFabClientAPI::GetAllUsersCharacters(FClientListUsersCharactersRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetAllUsersCharacters";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterLeaderboard(FClientGetCharacterLeaderboardRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterLeaderboard";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CharacterType.IsEmpty() || request.CharacterType == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }

    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the details of all title-specific statistics for the user */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterStatistics(FClientGetCharacterStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterStatistics";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of ranked characters for the given statistic, centered on the requested Character ID */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardAroundCharacter(FClientGetLeaderboardAroundCharacterRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardAroundCharacter";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CharacterType.IsEmpty() || request.CharacterType == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves a list of all of the user's characters for the given statistic. */
UPlayFabClientAPI* UPlayFabClientAPI::GetLeaderboardForUserCharacters(FClientGetLeaderboardForUsersCharactersRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetLeaderboardForUserCharacters";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatisticName.IsEmpty() || request.StatisticName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Grants the specified character type to the user. */
UPlayFabClientAPI* UPlayFabClientAPI::GrantCharacterToUser(FClientGrantCharacterToUserRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GrantCharacterToUser";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.ItemId.IsEmpty() || request.ItemId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ItemId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ItemId"), request.ItemId);
    }

    if (request.CharacterName.IsEmpty() || request.CharacterName == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterName"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterName"), request.CharacterName);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Updates the values of the specified title-specific statistics for the specific character */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateCharacterStatistics(FClientUpdateCharacterStatisticsRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateCharacterStatistics";
    manager->useSessionTicket = false;


    // Setup request object
    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.CharacterStatistics != NULL) OutRestJsonObj->SetObjectField(TEXT("CharacterStatistics"), request.CharacterStatistics);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////
/** Retrieves the title-specific custom data for the character which is readable and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterData(FClientGetCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterData";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Retrieves the title-specific custom data for the character which can only be read by the client */
UPlayFabClientAPI* UPlayFabClientAPI::GetCharacterReadOnlyData(FClientGetCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetCharacterReadOnlyData";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    }
    else
    {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Creates and updates the title-specific custom data for the user's character which is readable  and writable by the client */
UPlayFabClientAPI* UPlayFabClientAPI::UpdateCharacterData(FClientUpdateCharacterDataRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/UpdateCharacterData";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.CharacterId.IsEmpty() || request.CharacterId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    if (request.Data != NULL) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    }
    else
    {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    if (request.Permission == EPermissionEnum::PUBLIC) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Public"));
    if (request.Permission == EPermissionEnum::PRIVATE) OutRestJsonObj->SetStringField(TEXT("Permission"), TEXT("Private"));


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Amazon-Specific APIs
//////////////////////////////////////////////////////
/** Validates with Amazon that the receipt for an Amazon App Store in-app purchase is valid and that it matches the purchased catalog item */
UPlayFabClientAPI* UPlayFabClientAPI::ValidateAmazonIAPReceipt(FClientValidateAmazonReceiptRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/ValidateAmazonIAPReceipt";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.ReceiptId.IsEmpty() || request.ReceiptId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("ReceiptId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("ReceiptId"), request.ReceiptId);
    }

    if (request.UserId.IsEmpty() || request.UserId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("UserId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("UserId"), request.UserId);
    }

    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    if (request.CurrencyCode.IsEmpty() || request.CurrencyCode == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("CurrencyCode"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("CurrencyCode"), request.CurrencyCode);
    }

    OutRestJsonObj->SetNumberField(TEXT("PurchasePrice"), request.PurchasePrice);


    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Trading
//////////////////////////////////////////////////////
/** Accepts an open trade. If the call is successful, the offered and accepted items will be swapped between the two players' inventories. */
UPlayFabClientAPI* UPlayFabClientAPI::AcceptTrade(FClientAcceptTradeRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AcceptTrade";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.OfferingPlayerId.IsEmpty() || request.OfferingPlayerId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OfferingPlayerId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OfferingPlayerId"), request.OfferingPlayerId);
    }

    if (request.TradeId.IsEmpty() || request.TradeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }

    // Check to see if string is empty
    if (request.AcceptedInventoryInstanceIds.IsEmpty() || request.AcceptedInventoryInstanceIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AcceptedInventoryInstanceIds"));
    }
    else
    {
        TArray<FString> AcceptedInventoryInstanceIdsArray;
        FString(request.AcceptedInventoryInstanceIds).ParseIntoArray(AcceptedInventoryInstanceIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("AcceptedInventoryInstanceIds"), AcceptedInventoryInstanceIdsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Cancels an open trade. */
UPlayFabClientAPI* UPlayFabClientAPI::CancelTrade(FClientCancelTradeRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/CancelTrade";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.TradeId.IsEmpty() || request.TradeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Gets all trades the player has either opened or accepted, optionally filtered by trade status. */
UPlayFabClientAPI* UPlayFabClientAPI::GetPlayerTrades(FClientGetPlayerTradesRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetPlayerTrades";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.StatusFilter.IsEmpty() || request.StatusFilter == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("StatusFilter"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("StatusFilter"), request.StatusFilter);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Gets the current status of an existing trade. */
UPlayFabClientAPI* UPlayFabClientAPI::GetTradeStatus(FClientGetTradeStatusRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/GetTradeStatus";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.OfferingPlayerId.IsEmpty() || request.OfferingPlayerId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OfferingPlayerId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("OfferingPlayerId"), request.OfferingPlayerId);
    }

    if (request.TradeId.IsEmpty() || request.TradeId == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("TradeId"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("TradeId"), request.TradeId);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

/** Opens a new outstanding trade. */
UPlayFabClientAPI* UPlayFabClientAPI::OpenTrade(FClientOpenTradeRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/OpenTrade";
    manager->useSessionTicket = true;


    // Setup request object
    // Check to see if string is empty
    if (request.OfferedInventoryInstanceIds.IsEmpty() || request.OfferedInventoryInstanceIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("OfferedInventoryInstanceIds"));
    }
    else
    {
        TArray<FString> OfferedInventoryInstanceIdsArray;
        FString(request.OfferedInventoryInstanceIds).ParseIntoArray(OfferedInventoryInstanceIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("OfferedInventoryInstanceIds"), OfferedInventoryInstanceIdsArray);
    }

    // Check to see if string is empty
    if (request.RequestedCatalogItemIds.IsEmpty() || request.RequestedCatalogItemIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("RequestedCatalogItemIds"));
    }
    else
    {
        TArray<FString> RequestedCatalogItemIdsArray;
        FString(request.RequestedCatalogItemIds).ParseIntoArray(RequestedCatalogItemIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("RequestedCatalogItemIds"), RequestedCatalogItemIdsArray);
    }

    // Check to see if string is empty
    if (request.AllowedPlayerIds.IsEmpty() || request.AllowedPlayerIds == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("AllowedPlayerIds"));
    }
    else
    {
        TArray<FString> AllowedPlayerIdsArray;
        FString(request.AllowedPlayerIds).ParseIntoArray(AllowedPlayerIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("AllowedPlayerIds"), AllowedPlayerIdsArray);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}


///////////////////////////////////////////////////////
// Advertising
//////////////////////////////////////////////////////
/** Attributes an install for advertisment. */
UPlayFabClientAPI* UPlayFabClientAPI::AttributeInstall(FClientAttributeInstallRequest request)
{
    // Objects containing request data
    UPlayFabClientAPI* manager = NewObject<UPlayFabClientAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();

    // Setup the request
    manager->PlayFabRequestURL = "/Client/AttributeInstall";
    manager->useSessionTicket = true;


    // Setup request object
    if (request.Idfa.IsEmpty() || request.Idfa == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Idfa"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Idfa"), request.Idfa);
    }

    if (request.Android_Id.IsEmpty() || request.Android_Id == "")
    {
        OutRestJsonObj->SetFieldNull(TEXT("Android_Id"));
    }
    else
    {
        OutRestJsonObj->SetStringField(TEXT("Android_Id"), request.Android_Id);
    }



    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}



void UPlayFabClientAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    FPlayFabBaseModel myResponse;

    // Check we have result to process futher
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.ErrorCode = 500;
        myResponse.responseError.ErrorName = "Request Error";
        myResponse.responseError.ErrorMessage = "HTTP Request Error";

        myResponse.responseData = ResponseJsonObj;

        Client_proxy->OnPlayFabResponse.Broadcast(myResponse, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
    {
        if (!ResponseJsonObj->GetRootObject().IsValid())
        {
            // As we assume it's recommended way to use current class, but not the only one,
            // it will be the warning instead of error
            UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));
        }
    }

    // Serialize data to json string
    FString InputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&InputString);
    FJsonSerializer::Serialize(ResponseJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *InputString);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;

    if (isLoginRequest)
    {
        IPlayFab* pfSettings = &(IPlayFab::Get());
        pfSettings->setSessionTicket(myResponse.responseData->GetObjectField("data")->GetStringField("SessionTicket"));
        bool needsAttribution = myResponse.responseData->GetObjectField("data")->GetBoolField("SessionTicket");
        if (needsAttribution && !pfSettings->DisableAdvertising && !pfSettings->AdvertisingIdType.IsEmpty() && !pfSettings->AdvertisingIdValue.IsEmpty())
        {
            FClientAttributeInstallRequest request;
            bool makeAttrCall = true;
            if (pfSettings->AdvertisingIdType == IPlayFab::AD_TYPE_IDFA)
                request.Idfa = pfSettings->AdvertisingIdValue;
            else if (pfSettings->AdvertisingIdType == IPlayFab::AD_TYPE_ANDROID_ID)
                request.Android_Id = pfSettings->AdvertisingIdValue;
            else
                makeAttrCall = false;
            if (makeAttrCall)
            {
                auto callObj = AttributeInstall(request);
                callObj->Activate();
                if (callObj->IsValidLowLevel())
                    callObj->ConditionalBeginDestroy();
            }
        }
    }

    // Broadcast the result event
    Client_proxy->OnPlayFabResponse.Broadcast(myResponse, true);
}

void UPlayFabClientAPI::Activate()
{
    FString RequestUrl = TEXT("https://") + IPlayFab::Get().getGameTitleId() + IPlayFab::PlayFabURL;

    // Build the full request url
    if (cloudScript)
    {
        RequestUrl = TEXT("https://") + IPlayFab::Get().getGameTitleId() + IPlayFab::PlayFabLogicURL + FString::FromInt(IPlayFab::Get().CloudScriptVersion) + TEXT("/prod");
    }

    RequestUrl = RequestUrl + PlayFabRequestURL;

    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);

    if (useSessionTicket)
    {
        HttpRequest->SetHeader("X-Authentication", IPlayFab::Get().getSessionTicket());
    }
    if (useSecretKey)
    {
        HttpRequest->SetHeader("X-SecretKey", IPlayFab::Get().getSecretApiKey());
    }

    // Set verb
    HttpRequest->SetVerb("POST");


    // Set content-type
    HttpRequest->SetHeader("Content-Type", "application/json");

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    // Apply additional headers
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
    {
        HttpRequest->SetHeader(It.Key(), It.Value());
    }

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabClientAPI::OnProcessRequestComplete);

    // Execute the request
    HttpRequest->ProcessRequest();
}

void UPlayFabClientAPI::ResetResponseData()
{
    if (ResponseJsonObj != NULL)
    {
        ResponseJsonObj->Reset();
    }
    else
    {
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    }

    bIsValidJsonResponse = false;
}
