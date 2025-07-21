// MyFPSHUD.cpp
#include "MyFPSHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"

void AMyFPSHUD::DrawHUD()
{
    Super::DrawHUD();

    float DeltaSeconds = GetWorld()->GetDeltaSeconds();
    FrameTimes.Add(DeltaSeconds);

    // Limit to last 100 frames
    if (FrameTimes.Num() > 100)
        FrameTimes.RemoveAt(0);

    float AvgFPS = CalculateAverageFPS();
    FString FPSDisplay = FString::Printf(TEXT("FPS: %.2f"), AvgFPS);

    // Draw it on screen
    DrawText(FPSDisplay, FColor::Green, 50, 50, nullptr, 1.5f);
}

float AMyFPSHUD::CalculateAverageFPS() const
{
    if (FrameTimes.Num() == 0) return 0.f;

    float Total = 0.f;
    for (float Time : FrameTimes)
        Total += Time;

    float AvgDelta = Total / FrameTimes.Num();
    return AvgDelta > 0 ? 1.f / AvgDelta : 0.f;
}