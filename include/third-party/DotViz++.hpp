#ifndef DOTVIZ_PLUS_PLUS_HPP
#define DOTVIZ_PLUS_PLUS_HPP

#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>

namespace DotViz {
	class DVNodeStyle {
		::std::string __shape__;
		::std::string __color__;
		::std::string __style__;
		::std::string __fill_color__;
		::std::string __font_color__;
	public:
		DVNodeStyle(::std::string shape = "box", 
		            ::std::string color = "#FFDEAD",
		            ::std::string style = "rounded, solid, filled", 
		            ::std::string fill_color = "#FFDEAD",
		            ::std::string font_color = "#FF0000");
		~DVNodeStyle();

		inline DVNodeStyle &setShape(::std::string val);
		inline DVNodeStyle &setColor(::std::string val);
		inline DVNodeStyle &setStyle(::std::string val);
		inline DVNodeStyle &setFillColor(::std::string val);
		inline DVNodeStyle &setFontColor(::std::string val);

		inline ::std::string getShape() const;
		inline ::std::string getColor() const;
		inline ::std::string getStyle() const;
		inline ::std::string getFillColor() const;
		inline ::std::string getFontColor() const;
	};

	class DVLinkStyle {
		::std::string __color__;
		::std::string __style__;
	public:
		DVLinkStyle(::std::string color = "#9ACD32",
		            ::std::string style = "solid");
		~DVLinkStyle();

		inline DVLinkStyle &setColor(::std::string val);
		inline DVLinkStyle &setStyle(::std::string val);

		::std::string getColor() const;
		::std::string getStyle() const;
	};

	void dvBegin(::std::string path, ::std::string name);

	void dvNode(long long id, ::std::string label);
	inline DVNodeStyle &dvNodeStyle();

	void dvLink(long long id0, long long id1, bool directed = true);
	inline DVLinkStyle &dvLinkStyle();

	void dvEnd();
	void dvRender(::std::string in, ::std::string out);
}

#endif // DOTVIZ_PLUS_PLUS_HPP
