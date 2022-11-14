// Aim Training Game. Fedosov Vladislav

#include "AccuracyPlayerController.h"
#include "AimTrainingProject/GameModes/AccuracyGameMode.h"

void AAccuracyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		const auto GameMode = Cast<AAccuracyGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &AAccuracyPlayerController::OnMatchStateChanged);
		}
	}
}