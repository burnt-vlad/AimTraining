// Aim Training Game. Fedosov Vladislav


#include "AccuracyGameOverWidget.h"
#include "AimTrainingProject/GameModes/AccuracyGameMode.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UAccuracyGameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GoToReactionGameModeButton)
	{
		GoToReactionGameModeButton->OnClicked.AddDynamic(this, &UAccuracyGameOverWidget::OnGoToReactionGameMode);
	}
}

void UAccuracyGameOverWidget::OnGoToReactionGameMode()
{
	if (!GetWorld()) return;
	UGameplayStatics::OpenLevel(this, "ReactionLevel");
}




