// Aim Training Game. Fedosov Vladislav

#include "MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartTrainingButton)
	{
		StartTrainingButton->OnClicked.AddDynamic(this, &UMenuWidget::OnStartGame);
	}
}

void UMenuWidget::OnStartGame()
{
	if (!GetWorld()) return;
	UGameplayStatics::OpenLevel(this, "AccuracyLevel");
}

