#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
namespace sdds
{
	template <typename T>
	class Collection
	{
	private:
		std::string m_name{};
		T *m_array{};
		size_t m_size{};
		void (*m_observer)(const Collection<T> &, const T &){};

	public:
		Collection();
		virtual ~Collection();
		Collection(const std::string &name);
		Collection(const Collection &src) = delete;
		Collection &operator=(const Collection &src) = delete;
		Collection(Collection &&src);
		Collection &operator=(Collection &&src);

		const std::string &name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T> &, const T &));
		Collection<T> &operator+=(const T &item);
		T &operator[](size_t idx) const;
		T *operator[](const std::string &title) const;

		friend std::ostream &operator<<(std::ostream &os, const Collection<T> &c)
		{
			for (size_t i = 0; i < c.size(); ++i)
			{
				os << c[i];
			}
			return os;
		}
	};

	template <typename T>
	Collection<T>::Collection() = default;

	template <typename T>
	Collection<T>::~Collection()
	{
		delete[] m_array;
	}

	template <typename T>
	Collection<T>::Collection(const std::string &name)
	{
		m_name = name;
	}

	template <typename T>
	Collection<T>::Collection(Collection &&src)
	{
		*this = std::move(src);
	}
	template <typename T>
	Collection<T> &Collection<T>::operator=(Collection &&src)
	{
		if (this != &src)
		{
			m_array = src.m_array;
			m_name = src.m_name;
			m_size = src.m_size;
			m_observer = src.m_observer;

			src.m_array = nullptr;
			src.m_name = "";
			src.m_size = 0u;
			src.m_observer = nullptr;
		}
		return *this;
	}

	template <typename T>
	const std::string &Collection<T>::name() const
	{
		return m_name;
	}

	template <typename T>
	size_t Collection<T>::size() const
	{
		return m_size;
	}

	template <typename T>
	void Collection<T>::setObserver(void (*observer)(const Collection<T> &, const T &))
	{
		m_observer = observer;
	}

	template <typename T>
	Collection<T> &Collection<T>::operator+=(const T &item)
	{
		bool found = false;
		for (size_t i = 0; i < m_size && !found; ++i)
		{
			if (m_array[i].title() == item.title())
			{
				found = true;
			}
		}
		if (!found)
		{
			T *temp = new T[m_size + 1];

			for (size_t i = 0; i < m_size; ++i)
			{
				temp[i] = m_array[i];
			}
			delete[] m_array;
			m_array = temp;
			m_size++;
			m_array[m_size - 1] = item;
			if (m_observer != nullptr)
			{
				m_observer(*this, item);
			}
		}
		return *this;
	}
	template <typename T>
	T &Collection<T>::operator[](size_t idx) const
	{
		if (idx >= m_size || idx < 0)
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. " + "Collection has [" + std::to_string(m_size) + "] items.");
		}
		else
		{
			return m_array[idx];
		}
	}
	template <typename T>
	T *Collection<T>::operator[](const std::string &title) const
	{
		int idx = -1;
		for (size_t i = 0; i < m_size; ++i)
		{
			if (m_array[i].title() == title)
			{
				idx = i;
			}
		}
		return idx == -1 ? nullptr : &m_array[idx];
	}

}
#endif
