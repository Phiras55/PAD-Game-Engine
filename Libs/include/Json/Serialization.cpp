#include <Json/Serialization.h>

namespace pad	{

void ISerializable::AddJsonToFile(const std::string& path, const json& j)
{
	if (!_access(path.c_str(), 0))
		_mkdir(path.c_str());
	std::ofstream file(path);
	file << j << "\n";
	file.close();
}

json ISerializable::LoadJsonFromFile(const std::string& path)
{
	json j;
	std::fstream f(path);
	if (f.is_open())
	{
		if (f.good())
			f >> j;
		f.close();
	}
	return j;
}

} // namespace pad

