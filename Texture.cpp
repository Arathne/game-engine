#include "Texture.h"

unsigned int Texture::idCounter_ = 0;

Texture::Texture (void):
	path_("Missing Path To Texture"),
	id_(++idCounter_)
{}

Texture::Texture (const char* path):
	path_(path),
	id_(++idCounter_)
{}

Texture::Texture (Texture & rhs):
	path_(rhs.path_),
	id_(rhs.idCounter_)
{}

Texture::~Texture (void) {}		
		
const char* Texture::getPath (void) const
{
	return path_;
}

unsigned int Texture::getId (void) const
{
	return id_;
}

const Texture & Texture::operator = (const Texture & rhs)
{
	if ( &rhs != &(*this) )
	{
		path_ = rhs.path_;
		id_ = rhs.id_;
	}

	return *this;	
}

bool Texture::operator == (const Texture & rhs)
{
	bool equal = true;

	if (id_ != rhs.id_ || path_ != rhs.path_)
		equal = false;

	return equal;
}
