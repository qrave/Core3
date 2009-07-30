/*
 *	server/zone/objects/tangible/Container.cpp generated by engine3 IDL compiler 0.60
 */

#include "Container.h"

/*
 *	ContainerStub
 */

Container::Container(LuaObject* templateData) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new ContainerImplementation(templateData);
	_impl->_setStub(this);

	((ContainerImplementation*) _impl)->_serializationHelperMethod();
}

Container::Container(DummyConstructorParameter* param) : TangibleObject(param) {
}

Container::~Container() {
}

/*
 *	ContainerImplementation
 */

ContainerImplementation::~ContainerImplementation() {
}

void ContainerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Container*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ContainerImplementation::_getStub() {
	return _this;
}

ContainerImplementation::operator const Container*() {
	return _this;
}

void ContainerImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

}

/*
 *	ContainerAdapter
 */

ContainerAdapter::ContainerAdapter(ContainerImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* ContainerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	ContainerHelper
 */

ContainerHelper* ContainerHelper::staticInitializer = ContainerHelper::instance();

ContainerHelper::ContainerHelper() {
	className = "Container";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ContainerHelper::finalizeHelper() {
	ContainerHelper::finalize();
}

DistributedObject* ContainerHelper::instantiateObject() {
	return new Container(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ContainerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ContainerAdapter((ContainerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

