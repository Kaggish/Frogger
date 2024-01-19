#pragma once
#include "raylib.h"
#include <string_view>
#include <stdexcept>
#include <format>

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

struct Resource
{
	Texture2D FrogTexture;
};