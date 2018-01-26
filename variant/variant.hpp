template<typename... Types>
class Variant
 : private VariantStorage<Types...>,
   private VariantChoice<Types, Types...>...
{
  template<typename T, typename... OtherTypes>
    friend class VariantChoice;

 public:
  template<typename T> bool is() const;             // see variantis.hpp
  template<typename T> T& get() &;                  // see variantget.hpp
  template<typename T> T const& get() const&;       // see variantget.hpp
  template<typename T> T&& get() &&;                // see variantget.hpp

  // see variantvisit.hpp:
  template<typename R = ComputedResultType, typename Visitor>
    VisitResult<R, Visitor, Types&...> visit(Visitor&& vis) &; 
  template<typename R = ComputedResultType, typename Visitor>
    VisitResult<R, Visitor, Types const&...> visit(Visitor&& vis) const&;
  template<typename R = ComputedResultType, typename Visitor>
    VisitResult<R, Visitor, Types&&...> visit(Visitor&& vis) &&;

  using VariantChoice<Types, Types...>::VariantChoice...;
  Variant();                                        // see variantdefaultctor.hpp
  Variant(Variant const& source);                   // see variantcopyctor.hpp
  Variant(Variant&& source);                        // see variantmovector.hpp
  template<typename... SourceTypes>
    Variant(Variant<SourceTypes...> const& source); // variantcopyctortmpl.hpp
  template<typename... SourceTypes>
    Variant(Variant<SourceTypes...>&& source);

  using VariantChoice<Types, Types...>::operator=...;
  Variant& operator= (Variant const& source);       // see variantcopyassign.hpp
  Variant& operator= (Variant&& source);
  template<typename... SourceTypes>
    Variant& operator= (Variant<SourceTypes...> const& source);
  template<typename... SourceTypes>
    Variant& operator= (Variant<SourceTypes...>&& source);

  bool empty() const;

  ~Variant() { destroy(); }
  void destroy();                                   // see variantdestroy.hpp
};
