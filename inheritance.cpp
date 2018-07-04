class A {
private: int x;
protected: int y;
public: int z;
};
class B : public A {
private: int u;
protected: int v;
public: int w; void f() { x; }
};
class C: protected A {
private: int u;
protected: int v;
public: int w; void f() { x; }
};
class D: private A {
private: int u;
protected: int v;
public: int w; void f() { x; }
};
class E : public B {
public: void f() { x; u; }
};
class F : public C {
public: void f() { x; u; }
};
class G : public D {
public: void f() { x; y; z; u; }
};