#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};

    nob_cmd_append(&cmd, "clear");
    if (!nob_cmd_run(&cmd)) return 1;

    nob_cmd_append(&cmd, "test", "-d", ".build");
    if (!nob_cmd_run(&cmd)) {
        nob_cmd_append(&cmd, "mkdir", ".build");
        if (!nob_cmd_run(&cmd)) return 1;
    }

    nob_cmd_append(&cmd, "test", "-f", ".build/.gitignore");
    if (!nob_cmd_run(&cmd)) {
        nob_cmd_append(&cmd, "printf", "*");
        if (!nob_cmd_run(&cmd, .stdout_path = ".build/.gitignore")) return 1;
    }

    nob_cmd_append(&cmd, "cc", "-Wall", "-Wextra", "-o", ".build/exe", "src/main.c");
    if (!nob_cmd_run(&cmd)) return 1;

    nob_cmd_append(&cmd, "./.build/exe");
    if (!nob_cmd_run(&cmd)) return 1;

    return 0;
}
