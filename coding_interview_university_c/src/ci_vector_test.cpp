#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <ci_vector.h>
#include <doctest/doctest.h>

TEST_SUITE("ci_vector") {
	TEST_CASE("a vector can have a value pushed and popped.") {
		ci_vector a1 = ci_vector_int_init();

		int pushed_value = 100;
		ci_vector_int_push(&a1, pushed_value);

		int popped_value = ci_vector_int_pop(&a1);

		REQUIRE(pushed_value == popped_value);
	}

	TEST_CASE("a vector will return correctly whether it is empty or not") {
		ci_vector a1 = ci_vector_int_init();

		// A vector should begin empty.
		REQUIRE(ci_vector_int_is_empty(&a1));

		// Once a value is pushed the vector should no longer be empty.
		ci_vector_int_push(&a1, 0);
		REQUIRE(!ci_vector_int_is_empty(&a1));

		// Once that value has been popped the vector should be empty.
		(void)ci_vector_int_pop(&a1);
		REQUIRE(ci_vector_int_is_empty(&a1));
	}

	TEST_CASE("a vector will correctly report its size") {
		ci_vector a1 = ci_vector_int_init();

		int new_size = 3;
		for (int index = 0; index < new_size; ++index) {
			ci_vector_int_push(&a1, index);
		}

		REQUIRE(ci_vector_int_size(&a1) == new_size);
	}
}
