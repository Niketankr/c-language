#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int state; // 0 = OFF, 1 = ON
} Light;

void light_on(Light* light) {
    if (light) {
        light->state = 1;
        printf("%s is ON. 🟢\n", light->name);
    }
}

void light_off(Light* light) {
    if (light) {
        light->state = 0;
        printf("%s is OFF. 🔴\n", light->name);
    }
}

Light* create_light(const char* name) {
    Light* light = (Light*)malloc(sizeof(Light));
    if (light) {
        strcpy(light->name, name);
        light->state = 0; // Default state is OFF
    }
    return light;
}
typedef struct Command Command;

typedef void (*ExecuteFunc)(Command* cmd);

struct Command {
    ExecuteFunc execute;
    void* receiver;
};
void execute_light_on_cmd(Command* cmd) {
    Light* light = (Light*)cmd->receiver;
    light_on(light); 
    
}

Command* create_light_on_command(Light* light) {
    Command* cmd = (Command*)malloc(sizeof(Command));
    if (cmd) {
        cmd->execute = execute_light_on_cmd;
        cmd->receiver = light;
    }
    return cmd;
}
void execute_light_off_cmd(Command* cmd) {
    Light* light = (Light*)cmd->receiver;
    light_off(light); 
}

Command* create_light_off_command(Light* light) {
    Command* cmd = (Command*)malloc(sizeof(Command));
    if (cmd) {
        cmd->execute = execute_light_off_cmd;
        cmd->receiver = light;
    }
    return cmd;
}
typedef struct {
    Command* slot;
} RemoteControl;

void remote_set_command(RemoteControl* remote, Command* cmd) {
    remote->slot = cmd;
    printf("\nRemote control command set.\n");
}

void remote_press_button(RemoteControl* remote) {
    if (remote && remote->slot) {
        printf("Remote button pressed. Requesting command execution...\n");
        remote->slot->execute(remote->slot);
    }
}
int main() {
    printf("--- Command Pattern Demonstration (C) ---\n");
    Light* living_room_light = create_light("Living Room Light");
    Command* turn_on_cmd = create_light_on_command(living_room_light);
    Command* turn_off_cmd = create_light_off_command(living_room_light);
    RemoteControl remote = { .slot = NULL };
    remote_set_command(&remote, turn_on_cmd);
    remote_press_button(&remote);
    remote_set_command(&remote, turn_off_cmd);
    remote_press_button(&remote);
    free(living_room_light);
    free(turn_on_cmd);
    free(turn_off_cmd);

    return 0;
}
