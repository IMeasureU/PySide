// Global variables used to store argc and argv values
static int QCoreApplicationArgCount;
static char** QCoreApplicationArgValues;

int Sbk_QCoreApplication_Init(PyObject* self, PyObject* args, PyObject*)
{
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType<QCoreApplication >()))
        return -1;


    if (QCoreApplication::instance()) {
        PyErr_SetString(PyExc_RuntimeError, "A QCoreApplication instance already exists.");
        return -1;
    }

    int numArgs = PyTuple_GET_SIZE(args);
    if (numArgs != 1) {
        PyErr_BadArgument();
        return -1;
    }

    if (!Shiboken::sequenceToArgcArgv(PyTuple_GET_ITEM(args, 0), &QCoreApplicationArgCount, &QCoreApplicationArgValues, "PySideApp")) {
        PyErr_BadArgument();
        return -1;
    }

    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    QCoreApplicationWrapper* cptr = new QCoreApplicationWrapper(QCoreApplicationArgCount, QCoreApplicationArgValues);
    Shiboken::Object::setCppPointer(sbkSelf,
                                     Shiboken::SbkType<QCoreApplication>(),
                                     cptr);

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::Object::releaseOwnership(sbkSelf);

    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);
    PySide::Signal::updateSourceObject(self);
    cptr->metaObject();

    PySide::registerCleanupFunction(&PySide::destroyQCoreApplication);
    Py_INCREF(self);
    return 1;
}
