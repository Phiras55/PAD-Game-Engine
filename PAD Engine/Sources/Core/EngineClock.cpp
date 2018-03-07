namespace pad	{
namespace core	{

#pragma region Constructor / Destructor

double EngineClock::deltaTime		= 0;
Timepoint EngineClock::startTime	= std::chrono::high_resolution_clock::now();
Timepoint EngineClock::endTime		= std::chrono::high_resolution_clock::now();

#pragma endregion

#pragma region Member Functions

void EngineClock::Init()
{
	startTime = std::chrono::high_resolution_clock::now();
}

void EngineClock::Update()
{
	endTime		= std::chrono::high_resolution_clock::now();
	deltaTime	= std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
	startTime	= endTime;
}

#pragma endregion

} // namespace core
} // namespace pad