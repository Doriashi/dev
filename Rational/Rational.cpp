#pragma once

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double)denominator_;
    }

    Rational& operator+=(const Rational& r) {
        add(r);
        return *this;
    }

    Rational& operator+=(int d) {
        add(Rational(d));
        return *this;
    }

    Rational& operator-=(const Rational& r) {
        sub(r);
        return *this;
    }

    Rational& operator-=(int d) {
        sub(Rational(d));
        return *this;
    }

    Rational& operator*=(const Rational& r) {
        mul(r);
        return *this;
    }

    Rational& operator*=(int d) {
        mul(Rational(d));
        return *this;
    }

    Rational& operator/=(const Rational& r) {
        div(r);
        return *this;
    }

    Rational& operator/=(int d) {
        div(Rational(d));
        return *this;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        Rational r(this->numerator_, this->denominator_);
        r.neg();
        return r;
    }

    int get_numerator() const {
        return numerator_;
    }

    int get_denominator() const {
        return denominator_;
    }

    operator double() const {
        return to_double();
    }


private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational r1, Rational const& r2) {
    return r1 += r2;
}

Rational operator-(Rational r1, Rational const& r2) {
    return r1 -= r2;
}

Rational operator*(Rational r1, Rational const& r2) {
    return r1 *= r2;
}

Rational operator/(Rational r1, Rational const& r2) {
    return r1 /= r2;
}


bool operator<(Rational const& r1, Rational const& r2) {
    Rational r = r2 - r1;
    if (r.get_numerator() > 0) { return true; }
    else return false;
}

bool operator==(Rational const& r1, Rational const& r2) {
    Rational r = r2 - r1;
    if (r.get_numerator() == 0) { return true; }
    else return false;
}

bool operator!=(Rational const& r1, Rational const& r2) {
    return !(r1 == r2);
}

bool operator>(Rational const& r1, Rational const& r2) {
    return r2 < r1;
}

bool operator<=(Rational const& r1, Rational const& r2) {
    return !(r2 < r1);
}

bool operator>=(Rational const& r1, Rational const& r2) {
    return !(r1 < r2);
}