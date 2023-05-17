#include <iostream>
#include <string>
#include <iomanip>

std::string SecToString(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    seconds = seconds % 60;
    std::stringstream previewHumanTime;
    previewHumanTime << std::setfill('0') << std::setw(2) << hours << ":"
       << std::setfill('0') << std::setw(2) << minutes << ":"
       << std::setfill('0') << std::setw(2) << seconds;

    return previewHumanTime.str();
}

int main() {
    int inputInSecondsFormat;
    std::cout << "Podaj liczbe sekund: ";
    std::cin >> inputInSecondsFormat;

    std::string outputFormattedTime = SecToString(inputInSecondsFormat);
    std::cout << "Czas wyjsciowy(format HH:MM:SS): " << outputFormattedTime << std::endl;

    return 0;
}