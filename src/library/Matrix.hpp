#pragma once

#include "Model.hpp"
#include "ModelIndex.hpp"



template<class Type, Type defaultValue>
class Matrix
{
public:
	using ModelT = Model<Type, 2>;
	using ModelIndexT = ModelIndex<ModelT, Type>;
	using iterator = typename ModelT::iterator;
	
	Matrix();

	std::size_t size() const;

	ModelIndexT operator[](int index);

	iterator begin();
	iterator end();

private:
	ModelT _model { defaultValue };
};



template<class Type, Type defaultValue>
Matrix<Type, defaultValue>::Matrix()
{
}



template<class Type, Type defaultValue>
std::size_t Matrix<Type, defaultValue>::size() const
{
	return _model.size();
}



template<class Type, Type defaultValue>
typename Matrix<Type, defaultValue>::ModelIndexT Matrix<Type, defaultValue>::operator[](int index)
{
	ModelIndexT modelIndex { &_model };
	return modelIndex[index];
}



template<class Type, Type defaultValue>
typename Matrix<Type, defaultValue>::iterator Matrix<Type, defaultValue>::begin()
{
	return _model.begin();
}



template<class Type, Type defaultValue>
typename Matrix<Type, defaultValue>::iterator Matrix<Type, defaultValue>::end()
{
	return _model.end();
}
