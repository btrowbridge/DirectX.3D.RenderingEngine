#pragma once

#include <map>

namespace Library
{
	class ServiceContainer final
	{
	public:
		ServiceContainer() = default;
		ServiceContainer(const ServiceContainer& rhs) = delete;
		ServiceContainer& operator=(const ServiceContainer& rhs) = delete;

		void AddService(std::uint64_t typeID, void* service);
		void RemoveService(std::uint64_t typeID);
		void* GetService(std::uint64_t typeID) const;

		std::map<uint64_t, void*> mServices;
	};
}