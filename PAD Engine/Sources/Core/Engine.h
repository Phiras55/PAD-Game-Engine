namespace pad
{
namespace core
{

class Engine final
{
public:
	Engine();
	~Engine() = default;

	Engine(const Engine&)  = delete;
	Engine(const Engine&&) = delete;

public:
	void StartSimulation(); // Run()
	void Inputs();
	void Update(const float _deltaTime);
	void FixedUpdate(const float _deltaTime);
	void Render();

public:
	void operator=(const Engine&) = delete;
	void operator=(const Engine&&) = delete;
};

} // namespace core
} // namespace pad