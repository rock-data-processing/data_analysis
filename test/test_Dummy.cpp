#include <boost/test/unit_test.hpp>
#include <data_analysis/Dummy.hpp>

using namespace data_analysis;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    data_analysis::DummyClass dummy;
    dummy.welcome();
}
