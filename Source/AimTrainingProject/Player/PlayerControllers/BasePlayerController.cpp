// Aim Training Game. Fedosov Vladislav

#include "BasePlayerController.h"
#include "GameFramework/GameMode.h"


void ABasePlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    if (!InputComponent) return;
    InputComponent->BindAction("Pause", IE_Pressed, this, &ABasePlayerController::OnPausePressed);
}

void ABasePlayerController::OnPausePressed()
{
    if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
    GetWorld()->GetAuthGameMode()->SetPause(this);
}

void ABasePlayerController::OnMatchStateChanged(EMatchState State)
{
    if (State == EMatchState::InProgress)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}
