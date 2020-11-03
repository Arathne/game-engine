#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
	public:
		Texture (void);
		Texture (const char* path);
		Texture (Texture & rhs);

		~Texture (void);		
		
		const char* getPath (void) const;
		unsigned int getId (void) const;
		
		const Texture & operator = (const Texture & rhs);
		bool operator == (const Texture & rhs);

	private:
		static unsigned int idCounter_;
		const char* path_;
		unsigned int id_;
};

#endif
