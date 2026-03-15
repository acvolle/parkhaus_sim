
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

void test_ui_print_stats() 
{
    Stats test_stats = {12.3, 4, 5, 6.7, 8.9};
    
    // test successful execution
    assert(ui_print_stats(&test_stats) == 0);

    // test null pointer handling
    assert(ui_print_stats(NULL) == -1);
}

// Function creates a txt file which can be tested, valid == 0 leads to an invalid file
void create_test_file(const char *filename, int valid)
{
    FILE *fp = fopen(filename, "w");
    if (valid)
    {
        // print header lines
        for (int i; i < TXT_FILE_HEADER_LINES; i++)
        {
            fprintf(fp, "Header line\n");
        }

        // Data for test: Timestamp, Occ Rate, Cars Waiting, Max Wait, Avg Wait, Stress score
        fprintf(fp, "1, 80.00, 0, 0, 0.00, 0.00\n");
        fprintf(fp, "2, 100.00, 10, 20, 12.50, 75.00\n");
    }
    else // invalid file should be printed
    {
        fprintf(fp, "File contains only a single line\n");
    }
    fclose(fp);
}

void test_ui_process_final_stats()
{

        // test null pointer handling
    assert(ui_process_final_stats(NULL) == -1);
    
    // test with valid file
    create_test_file("valid_test_log_file.txt", 1);
    FILE *valid_fp = fopen("valid_test_log_file.txt", "r");
    assert(valid_fp != NULL);
    assert(ui_process_final_stats(valid_fp) == 0);
    fclose(valid_fp);
    remove("valid_test_log_file.txt");

    // test handling of invalid file
    create_test_file("short_test_log_file.txt", 1);
    FILE *invalid_fp = fopen("short_test_log_file.txt", "r");
    assert(invalid_fp != NULL);
    assert(ui_process_final_stats(invalid_fp) == -1);
    fclose(invalid_fp);
    remove("short_test_log_file.txt");
}