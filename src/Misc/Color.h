#ifndef COLOR_H
#define COLOR_H

class Color
{
	public:
		Color (void);
		Color (unsigned int r, unsigned int g, unsigned int b, unsigned int a);
		Color (const Color & rhs);
		~Color (void);
		
		unsigned int red (void) const;
		unsigned int green (void) const;
		unsigned int blue (void) const;
		unsigned int alpha (void) const;
	
		const Color & operator = (const Color & rhs);
		
		static Color make (int r, int g, int b, int a);

	private:
		void check (int r, int g, int b, int a);
		
		unsigned char red_;
		unsigned char green_;
		unsigned char blue_;
		unsigned char alpha_;
};

#endif
