#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>

#include <third-party/DotViz++.hpp>

#define PANIC(mode, type, fmt, ...) \
{ \
	std::fprintf(std::stderr, fmt \
	             "Error comes from %d line, %s function from %s file", ##__VA_ARGS__ \
	             __LINE__, __PRETTY_FUNCTION__, __FILE__); \
	if (mode) \
		return type(); \
}

#define CHECK_PROCEEDING(type) \
if (!(::DotViz::__sys__::out)) \
	PANIC(true, type, "DotViz's not proceeding now!\n");

#define CHECK_NOT_PROCEEDING(type) \
if (::DotViz::__sys__::out) \
	PANIC(true, type, "DotViz's proceeding now\n");

#define CHECK_NODE_STYLE(type) \
if (!dvNodeStyle().getShape().length() || \
    !dvNodeStyle().getColor().length() || \
    !dvNodeStyle().getStyle().length() || \
    !dvNodeStyle().getFillColor().length() || \
    !dvNodeStyle().getFontColor().length()) \
	PANIC(false, type, "DotViz's node_style hasn't got some member");

#define CHECK_LINK_STYLE(type) \
if (!dvLinkStyle().getColor().length() || \
    !dvLinkStyle().getStyle().length()) \
	PANIC(false, type, "DotViz's link_style hasn't got some member");

namespace DotViz {
	namespace __sys__ {
		DVNodeStyle node_style;
		DVLinkStyle link_style;
		std::FILE *out;
	}

	DVNodeStyle::DVNodeStyle(::std::string shape /*= "box"*/,
	                         ::std::string color /*= "#FFDEAD"*/,
	                         ::std::string style /*= "rounded, solid, filled"*/,
	                         ::std::string fill_color /*= "#FFDEAD"*/,
	                         ::std::string font_color /*= "#FF0000"*/):
		__shape__(shape),
		__color__(color),
		__style__(style),
		__fill_color__(fill_color),
		__font_color__(font_color)
	{ }

	DVNodeStyle::~DVNodeStyle()
	{ }

	inline DVNodeStyle &DVNodeStyle::setShape(::std::string val) const
	{
		__shape__ = val;
		return *this;
	}
	
	inline DVNodeStyle &DVNodeStyle::setColor(::std::string val) const
	{
		__color__ = val;
		return *this;
	}

	inline DVNodeStyle &DVNodeStyle::setStyle(::std::string val) const
	{
		__style__ = val;
		return *this;
	}

	inline DVNodeStyle &DVNodeStyle::setFillColor(::std::string val) const
	{
		__fill_color__ = val;
		return *this;
	}

	inline DVNodeStyle &DVNodeStyle::setFontColor(::std::string val) const
	{
		__font_color__ = val;
		return *this;
	}

	inline ::std::string getShape() const
	{
		return __shape__;
	}

	inline ::std::string getColor() const
	{
		return __color__;
	}

	inline ::std::string getStyle() const
	{
		return __style__;
	}

	inline ::std::string getFillColor() const
	{
		return __fill_color__;
	}

	inline ::std::string getFontColor() const
	{
		return __font_color__;
	}

	DVLinkStyle::DVLinkStyle(::std::string color /*= "#9ACD32"*/,
	                         ::std::string style /*= "solid"*/):
		__color__(color),
		__style__(style)
	{ }

	DVLinkStyle::~DVLinkStyle()
	{ }

	inline DVLinkStyle &DVLinkStyle::setColor(::std::string val)
	{
		__color__ = val;
		return *this;
	}

	inline DVLinkStyle &DVLinkStyle::setStyle(::std::string val)
	{
		__style__ = val;
		return *this;
	}

	void dvBegin(::std::string path, ::std::string name)
	{
		CHECK_NOT_PROCEEDING(void)
		__sys__::out = std::fopen(path.c_str(), "w");
		CHECK_PROCEEDING(void)

		::std::fprintf(__sys__::out, "# By DotViz++\ndigraph %s {\n", name.c_str());
	}

	void dvNode(long long unsigned id, ::std::string label)
	{
		CHECK_PROCEEDING(void)
		CHECK_NODE_STYLE(void)

		::std::fprintf(__sys__::out, "\tNode_%d[", id);

		if (dvNodeStyle().getShape().length())
			::std::fprintf(__sys__::out, "shape=\"%s\" ", dvNodeStyle().getShape().c_str());

		if (dvNodeStyle().getColor().length())
			::std::fprintf(__sys__::out, "color=\"%s\" ", dvNodeStyle().getColor().c_str());

		if (dvNodeStyle().getFillColor().length())
			::std::fprintf(__sys__::out, "fillcolor=\"%s\" ", dvNodeStyle().getFillColor().c_str());

		if (dvNodeStyle().getFontColor().length())
			::std::fprintf(__sys__::out, "fontcolor=\"%s\" ", dvNodeStyle().getFontColor().c_str());

		if (dvNodeStyle().getStyle().length())
			::std::fprintf(__sys__::out, "style=\"%s\" ", dvNodeStyle().getStyle().c_str());

		::std::fprintf(__sys__::out, "weight=\"1\" label=\"%s\"];\n", label.c_str());

		CHECK_NODE_STYLE(void)
		CHECK_PROCEEDING(void)
	}

	inline DVNodeStyle &dvNodeStyle()
	{
		return __sys__::node_style;
	}

	void dvLink(long long unsigned id0, long long unsigned id1, bool directed /*= true*/)
	{
		CHECK_PROCEEDING(void)
		CHECK_LINK_STYLE(void)

		::std::fprintf(__sys__::out, "\tNode_%llu%sNode_%llu", id0, ((directed)?("->"):("--")), id1);

		CHECK_LINK_STYLE(void)
		CHECK_PROCEEDING(void)
	}

	inline DVNodeStyle &dvLinkStyle()
	{
		return __sys__::link_style;
	}

	void dvEnd()
	{
		CHECK_PROCEEDING(void)
		
		::std::fprintf(__sys__::out, "}\n# By DotViz++\n");
	}

	void dvRender(::std::string in, ::std::string out)
	{
		std::stringstream val;
		val << "dot" << " -T" << get_out_type(out) << " " << in << " -o " << out;

		system(val.str().c_str());
	}
}
