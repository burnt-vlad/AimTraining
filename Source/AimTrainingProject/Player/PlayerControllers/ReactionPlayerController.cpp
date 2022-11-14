// Aim Training Game. Fedosov Vladislav

#include "ReactionPlayerController.h"
#include "AimTrainingProject/GameModes/ReactionGameMode.h"

void AReactionPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		const auto GameMode = Cast<AReactionGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &AReactionPlayerController::OnMatchStateChanged);
		}
	}
}
