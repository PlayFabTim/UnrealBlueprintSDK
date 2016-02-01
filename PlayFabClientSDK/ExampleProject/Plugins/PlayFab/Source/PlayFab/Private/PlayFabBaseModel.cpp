//////////////////////////////////////////////////////////////////////////////////////////////
// This files holds the code for the play fab base model.
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabBaseModel.h"

void FPlayFabError::decodeError(UPlayFabJsonObject* responseData)
{

    // Check if we have an error
	int code = 0;
	if (responseData->HasField("code"))
	{
		code = int(responseData->GetNumberField("code"));
	}
    if (code != 200) // We have an error
    {
        hasError = true;
		if (responseData->HasField("errorCode"))
		{
			ErrorCode = int(responseData->GetNumberField("errorCode"));
		}
		if (responseData->HasField("error"))
		{
			ErrorName = responseData->GetStringField("error");
		}
		if (responseData->HasField("errorMessage"))
		{
			ErrorMessage = responseData->GetStringField("errorMessage");
		}
		if (responseData->HasField("errorDetails"))
		{
			ErrorDetails = responseData->GetStringField("errorDetails");
		}
    }
    else { hasError = false; }

}