#pragma once
#include "raylib.h"
#include <string_view>
#include <stdexcept>
#include <format>
#include <vector>

using namespace std::literals::string_view_literals;

struct TextureData
{
	Texture2D m_texture;
	explicit TextureData(std::string_view Path)
	{
		m_texture = LoadTexture(Path.data());
		if (m_texture.id <= 0)
		{
			//Throw some error
		}
	}

	TextureData(const TextureData& other) = delete;
	TextureData& operator=(const TextureData& other) = delete;

	TextureData(TextureData&& other) noexcept
	{
		std::swap(other.m_texture, m_texture);
	}

	TextureData& operator=(TextureData&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(other.m_texture, m_texture);
		}
		return *this;
	}
	
	~TextureData()
	{
		UnloadTexture(m_texture);
	}

	const Texture2D& get() const noexcept
	{
		return m_texture;
	}
};

struct SoundData
{
	Sound m_sound;
	explicit SoundData(std::string_view Path)
	{
		m_sound = LoadSound(Path.data());
	}

	SoundData(const SoundData& other) = delete;
	SoundData& operator=(const SoundData& other) = delete;

	SoundData(SoundData&& other) noexcept
	{
		std::swap(other.m_sound, m_sound);
	}

	SoundData& operator=(SoundData&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(other.m_sound, m_sound);
		}
		return *this;
	}

	~SoundData()
	{
		UnloadSound(m_sound);
	}

	const Sound& get() const noexcept
	{
		return m_sound;
	}
};

struct Resource
{
	std::vector<TextureData> LogTextures;
	std::vector<TextureData> CarTextures;
	explicit Resource()
	{
		LogTextures.emplace_back("./Assets/Log100.png"sv);
		LogTextures.emplace_back("./Assets/Log150.png"sv);
		LogTextures.emplace_back("./Assets/Log250.png"sv);

		CarTextures.emplace_back("Assets/Racecar.png"sv);
		CarTextures.emplace_back("Assets/Sedan.png"sv);
		CarTextures.emplace_back("Assets/Tractor.png"sv);
		CarTextures.emplace_back("Assets/Truck.png"sv);
		CarTextures.emplace_back("Assets/Bus.png"sv);
	}
	TextureData FrogTexture = TextureData("./Assets/Frog.png"sv);

	SoundData CrashSound = SoundData("./Assets/Crash.ogg"sv);
	SoundData BackgroundSound = SoundData("./Assets/Background.ogg"sv);
};