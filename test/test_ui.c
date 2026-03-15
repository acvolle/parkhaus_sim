
#include "../include/ui.h"

void test_ui_get_params()
{
    // test null pointer handling
    assert(ui_get_params(NULL) == -1);

    // other cases cannot be tested without user input
}

// function tests ui_write_head and ui_write_stats
void test_ui_write_functions()
{
    Config test_config = {100, 10, 69, 42, 333};
    Stats test_stats = {50.0, 5, 187, 5.0, 25.0};
    FILE *fp = fopen("test_output.txt", "w");
    assert(fp != NULL);

    // test if execution was successfull
    assert(ui_write_head(&test_config, "1, 2, 3", fp) == 0);
    assert(ui_write_stats(&test_stats, fp) == 0);

    // test null pointer handling
    assert(ui_write_head(NULL, NULL, fp) == -1);
    assert(ui_write_stats(NULL, fp) == -1);

    fclose(fp);
    remove("test_output.txt");
}