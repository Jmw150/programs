from collections import namedtuple
import math
 
class Q(namedtuple('Quaternion', 'real, i, j, k')):
    'Quaternion type: Q(real=0.0, i=0.0, j=0.0, k=0.0)' 
 
    __slots__ = () 
 
    def __new__(_cls, real=0.0, i=0.0, j=0.0, k=0.0):
        'Defaults all parts of quaternion to zero'
        return super().__new__(_cls, float(real), float(i), float(j), float(k))
 
    def conjugate(self):
        return Q(self.real, -self.i, -self.j, -self.k)
 
    def _norm2(self):
        return sum( x*x for x in self)
 
    def norm(self):
        return math.sqrt(self._norm2())
 
    def reciprocal(self):
        n2 = self._norm2()
        return Q(*(x / n2 for x in self.conjugate())) 
 
    def __str__(self):
        'Shorter form of Quaternion as string'
        return 'Q(%g, %g, %g, %g)' % self
 
    def __neg__(self):
        return Q(-self.real, -self.i, -self.j, -self.k)
 
    def __add__(self, other):
        if type(other) == Q:
            return Q( *(s+o for s,o in zip(self, other)) )
        try:
            f = float(other)
        except:
            return NotImplemented
        return Q(self.real + f, self.i, self.j, self.k)
 
    def __radd__(self, other):
        return Q.__add__(self, other)
 
    def __mul__(self, other):
        if type(other) == Q:
            a1,b1,c1,d1 = self
            a2,b2,c2,d2 = other
            return Q(
                 a1*a2 - b1*b2 - c1*c2 - d1*d2,
                 a1*b2 + b1*a2 + c1*d2 - d1*c2,
                 a1*c2 - b1*d2 + c1*a2 + d1*b2,
                 a1*d2 + b1*c2 - c1*b2 + d1*a2 )
        try:
            f = float(other)
        except:
            return NotImplemented
        return Q(self.real * f, self.i * f, self.j * f, self.k * f)
 
    def __rmul__(self, other):
        return Q.__mul__(self, other)
 
    def __truediv__(self, other):
        if type(other) == Q:
            return self.__mul__(other.reciprocal())
        try:
            f = float(other)
        except:
            return NotImplemented
        return Q(self.real / f, self.i / f, self.j / f, self.k / f)
 
    def __rtruediv__(self, other):
        return other * self.reciprocal()
 
    __div__, __rdiv__ = __truediv__, __rtruediv__
 
Quaternion = Q       
 
q  = Q(1, 2, 3, 4)
q1 = Q(2, 3, 4, 5)
q2 = Q(3, 4, 5, 6)
r  = 7

""" test suit
>>> q
Quaternion(real=1.0, i=2.0, j=3.0, k=4.0)
>>> q1
Quaternion(real=2.0, i=3.0, j=4.0, k=5.0)
>>> q2
Quaternion(real=3.0, i=4.0, j=5.0, k=6.0)
>>> r
7
>>> q.norm()
5.477225575051661
>>> q1.norm()
7.3484692283495345
>>> q2.norm()
9.273618495495704
>>> -q
Quaternion(real=-1.0, i=-2.0, j=-3.0, k=-4.0)
>>> q.conjugate()
Quaternion(real=1.0, i=-2.0, j=-3.0, k=-4.0)
>>> r + q
Quaternion(real=8.0, i=2.0, j=3.0, k=4.0)
>>> q + r
Quaternion(real=8.0, i=2.0, j=3.0, k=4.0)
>>> q1 + q2
Quaternion(real=5.0, i=7.0, j=9.0, k=11.0)
>>> q2 + q1
Quaternion(real=5.0, i=7.0, j=9.0, k=11.0)
>>> q * r
Quaternion(real=7.0, i=14.0, j=21.0, k=28.0)
>>> r * q
Quaternion(real=7.0, i=14.0, j=21.0, k=28.0)
>>> q1 * q2
Quaternion(real=-56.0, i=16.0, j=24.0, k=26.0)
>>> q2 * q1
Quaternion(real=-56.0, i=18.0, j=20.0, k=28.0)
>>> assert q1 * q2 != q2 * q1
>>> 
>>> i, j, k = Q(0,1,0,0), Q(0,0,1,0), Q(0,0,0,1)
>>> i*i
Quaternion(real=-1.0, i=0.0, j=0.0, k=0.0)
>>> j*j
Quaternion(real=-1.0, i=0.0, j=0.0, k=0.0)
>>> k*k
Quaternion(real=-1.0, i=0.0, j=0.0, k=0.0)
>>> i*j*k
Quaternion(real=-1.0, i=0.0, j=0.0, k=0.0)
>>> q1 / q2
Quaternion(real=0.7906976744186047, i=0.023255813953488358, j=-2.7755575615628914e-17, k=0.046511627906976744)
>>> q1 / q2 * q2
Quaternion(real=2.0000000000000004, i=3.0000000000000004, j=4.000000000000001, k=5.000000000000001)
>>> q2 * q1 / q2
Quaternion(real=2.0, i=3.465116279069768, j=3.906976744186047, k=4.767441860465116)
>>> q1.reciprocal() * q1
Quaternion(real=0.9999999999999999, i=0.0, j=0.0, k=0.0)
>>> q1 * q1.reciprocal()
Quaternion(real=0.9999999999999999, i=0.0, j=0.0, k=0.0)
"""
