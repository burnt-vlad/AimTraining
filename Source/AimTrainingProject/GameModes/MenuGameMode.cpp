// Aim Training Game. Fedosov Vladislav

#include "MenuGameMode.h"
#include "AimTrainingProject/Player/PlayerControllers/MenuPlayerController.h"
#include "AimTrainingProject/UI/HUDs/MenuHUD.h"

AMenuGameMode::AMenuGameMode()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}