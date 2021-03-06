#ifndef TASK_TIMERS_HPP
#define TASK_TIMERS_HPP



struct templates
{
    const std::string _value = "templates";
};

struct design_patterns
{
    const std::string _value = "design patterns";
};

struct satter_generic
{
    const std::string _value = "satter";
};

struct cormen
{
    const std::string _value = "cormen";
};

struct threads
{
    const std::string _value = "threads";
};

struct stroustrup
{
    const std::string _value = "stroustrup";
};

struct alexandrescu
{
    const std::string _value = "alexandrescu";
};

struct work
{
    const std::string _value = "work";
};

struct tests
{
    const std::string _value = "test knowledge";
};

struct dictionary
{
    const std::string _value = "dictionary";
};

struct movie_half
{
    const std::string _value = "movie half";
};

struct reading
{
    const std::string _value = "reading";
};

struct lunch
{
    const std::string _value = "lunch";
};

template <typename T>
struct taskName
{
    taskName()
        : name(typename T())
    {}
    const T name;
};

#endif // TASK_TIMERS_HPP

