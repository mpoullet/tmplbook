#ifndef BASE_MEMBER_PAIR_HPP
#define BASE_MEMBER_PAIR_HPP

template<typename Base, typename Member>
class BaseMemberPair : private Base {
  private:
    Member mem;
  public:
    // constructor
    BaseMemberPair (Base const & b, Member const & m)
     : Base(b), mem(m) {
    }

    // access base class data via first()
    Base const& base() const {
        return static_cast<Base const&>(*this);
    }
    Base& base() {
        return static_cast<Base&>(*this);
    }

    // access member data via second()
    Member const& member() const {
        return this->mem;
    }
    Member& member() {
        return this->mem;
    }
};

#endif // BASE_MEMBER_PAIR_HPP
