#ifndef AUTORELEASEPOINTER_HPP
#define AUTORELEASEPOINTER_HPP

#include <STDExtras.hpp>

namespace LLCCEP {
	template<typename T>
	class autoReleasePointer {
	public:
		autoReleasePointer():
			_val(0)
		{ }
		
		autoReleasePointer(T *ptr):
			_val(ptr)
		{ }
		
		autoReleasePointer(const autoReleasePointer &ref):
			_val(ref)
		{ }
		
		~autoReleasePointer()
		{
			if (_val)
				delete _val;
		}
		
		operator bool() const
		{
			return static_cast<bool>(_val);
		}
		
		operator T*() const
		{
			return _val;
		}
		
		T &operator*()
		{
			if (!_val) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"An attempt of access by null pointer\n"
					"of autoReleasePointer object(%p)!\n",
					this))
			}
		}
	private:
		T *_val;
	};
}

#endif // AUTORELEASEPOINTER_HPP