// Aim Training Game. Fedosov Vladislav


#include "MenuPlayerController.h"

void AMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}