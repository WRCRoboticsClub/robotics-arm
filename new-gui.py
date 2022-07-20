import tkinter
import tkinter.messagebox
import customtkinter
from PIL import Image, ImageTk
import os

customtkinter.set_appearance_mode("System")  # Modes: "System" (standard), "Dark", "Light"
customtkinter.set_default_color_theme("blue")  # Themes: "blue" (standard), "green", "dark-blue"
PATH = os.path.dirname(os.path.realpath(__file__))

class App(customtkinter.CTk):

    WIDTH = 780
    HEIGHT = 520

    def __init__(self):
        super().__init__()

        self.title("Robotic Arm GUI Controller")
        self.geometry(f"{App.WIDTH}x{App.HEIGHT}")
        self.protocol("WM_DELETE_WINDOW", self.on_closing)  # call .on_closing() when app gets closed

        # ============ create two frames ============

        # configure grid layout (2x1)
        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        self.frame_left = customtkinter.CTkFrame(master=self,
                                                 width=180,
                                                 corner_radius=0)
        self.frame_left.grid(row=0, column=0, sticky="nswe")

        self.frame_right = customtkinter.CTkFrame(master=self)
        self.frame_right.grid(row=0, column=1, sticky="nswe", padx=20, pady=20)

        # ============ frame_left ============

        # configure grid layout (1x11)
        self.frame_left.grid_rowconfigure(0, minsize=10)   # empty row with minsize as spacing
        self.frame_left.grid_rowconfigure(5, weight=1)  # empty row as spacing
        self.frame_left.grid_rowconfigure(8, minsize=20)    # empty row with minsize as spacing
        self.frame_left.grid_rowconfigure(11, minsize=10)  # empty row with minsize as spacing

        self.label_1 = customtkinter.CTkLabel(master=self.frame_left,
                                              text="CustomTkinter",
                                              text_font=("Roboto Medium", -16))  # font name and size in px
        self.label_1.grid(row=1, column=0, pady=10, padx=10)

        self.button_1 = customtkinter.CTkButton(master=self.frame_left,
                                                text="Connect",
                                                command=self.button_event)
        self.button_1.grid(row=2, column=0, pady=10, padx=20)

        self.button_2 = customtkinter.CTkButton(master=self.frame_left,
                                                text="Diconnect",
                                                command=self.button_event)
        self.button_2.grid(row=3, column=0, pady=10, padx=20)

       

        self.label_mode = customtkinter.CTkLabel(master=self.frame_left, text="Appearance Mode:")
        self.label_mode.grid(row=9, column=0, pady=0, padx=20, sticky="w")

        self.optionmenu_1 = customtkinter.CTkOptionMenu(master=self.frame_left,
                                                        values=["Light", "Dark", "System"],
                                                        command=self.change_appearance_mode)
        self.optionmenu_1.grid(row=10, column=0, pady=10, padx=20, sticky="w")

        # ============ frame_right ============

        # configure grid layout (3x7)
        self.frame_right.rowconfigure((0, 1, 2, 3), weight=1)
        self.frame_right.rowconfigure(7, weight=10)
        self.frame_right.columnconfigure((0, 1), weight=1)
        self.frame_right.columnconfigure(2, weight=0)

        self.frame_info = customtkinter.CTkFrame(master=self.frame_right)
        self.frame_info.grid(row=0, column=0, columnspan=2, rowspan=4, pady=20, padx=20, sticky="nsew")

        # ============ frame_info ============

        # configure grid layout (1x1)
        self.frame_info.rowconfigure(0, weight=1)
        self.frame_info.columnconfigure(0, weight=1)

        # load image with PIL and convert to PhotoImage
        image = Image.open(PATH + "/svg_pointless_robots.gif").resize((self.WIDTH, self.HEIGHT))
        self.bg_image = ImageTk.PhotoImage(image)
        self.label_info_1 = customtkinter.CTkLabel(master=self.frame_info,
                                                #    text="CTkLabel: Lorem ipsum dolor sit,\n" +
                                                #         "amet consetetur sadipscing elitr,\n" +
                                                #         "sed diam nonumy eirmod tempor" ,
                                                   image = self.bg_image,
                                                   height=100,
                                                   corner_radius=6,   
                                                   fg_color=("white", "gray38"),  
                                                   justify=tkinter.LEFT)
        self.label_info_1.grid(column=0, row=0, sticky="nwe")
       
        

        # self.progressbar = customtkinter.CTkProgressBar(master=self.frame_info)
        # self.progressbar.grid(row=1, column=0, sticky="ew", padx=15, pady=15)

        # ============ frame_right ============

        # self.slider_1 = customtkinter.CTkSlider(master=self.frame_right,
        #                                         from_=0,
        #                                         to=1,
        #                                         number_of_steps=3,
        #                                         command=self.progressbar.set)
        # self.slider_1.grid(row=4, column=0, columnspan=2, pady=10, padx=20, sticky="we")

        # self.slider_2 = customtkinter.CTkSlider(master=self.frame_right,
        #                                         command=self.progressbar.set)
        # self.slider_2.grid(row=5, column=0, columnspan=2, pady=10, padx=20, sticky="we")

        #base
        self.label_2 = customtkinter.CTkLabel(master=self.frame_right,
                                              text="Base",
                                              text_font=("Roboto Medium", -16)) 
        self.label_2.grid(row=4, column=0, pady=10, padx=10)
        self.button_3 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Turn Left",
                                                 command=self.base_turn_left)
        self.button_3.grid(row=4, column=1, pady=10, padx=20)
        self.button_3 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Turn Right",
                                                 command=self.base_turn_right)
        self.button_3.grid(row=4, column=2, pady=10, padx=20)

        #shoulder
        self.label_3 = customtkinter.CTkLabel(master=self.frame_right,
                                              text="Shoulder",
                                              text_font=("Roboto Medium", -16)) 
        self.label_3.grid(row=5, column=0, pady=10, padx=10)
        self.button_4 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Move up",
                                                 command=self.shoulder_move_up)
        self.button_4.grid(row=5, column=1, pady=10, padx=20)
        self.button_4 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Move down",
                                                 command=self.shoulder_move_up)
        self.button_4.grid(row=5, column=2, pady=10, padx=20)

        #wrist
        self.label_4 = customtkinter.CTkLabel(master=self.frame_right,
                                              text="Wrist",
                                              text_font=("Roboto Medium", -16)) 
        self.label_4.grid(row=6, column=0, pady=10, padx=10)
        self.button_5 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Turn Left",
                                                 command=self.wrist_turn_left)
        self.button_5.grid(row=6, column=1, pady=10, padx=20)
        self.button_5 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Turn Right",
                                                 command=self.wrist_turn_right)
        self.button_5.grid(row=6, column=2, pady=10, padx=20)

        #gripper
        self.label_4 = customtkinter.CTkLabel(master=self.frame_right,
                                              text="Gripper",
                                              text_font=("Roboto Medium", -16)) 
        self.label_4.grid(row=7, column=0, pady=10, padx=10)
        self.button_5 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Open",
                                                 command=self.gripper_open)
        self.button_5.grid(row=7, column=1, pady=10, padx=20)
        self.button_5 = customtkinter.CTkButton(master=self.frame_right,
                                                text="Close",
                                                 command=self.gripper_close)
        self.button_5.grid(row=7, column=2, pady=10, padx=20)

        # set default values
        self.optionmenu_1.set("Dark")
        

        # self.slider_1.set(0.2)
        # self.slider_2.set(0.7)
        # self.progressbar.set(0.5)


    def button_event(self):
        print("Button pressed")

    def base_turn_left(self):
        print("Base turn left")
    
    def base_turn_right(self):
        print("Base turn right")
    
    def shoulder_move_up(self):
        print("Shoulder move up")
    
    def shoulder_move_down(self):
        print("Shoulder move down")
    
    def wrist_turn_left(self):
        print("Wrist turn left")
    
    def wrist_turn_right(self):
        print("Wrist turn right")

    def gripper_open(self):
        print("Gripper open")
    
    def gripper_close(self):
        print("Gripper close")
    

    def change_appearance_mode(self, new_appearance_mode):
        customtkinter.set_appearance_mode(new_appearance_mode)

    def on_closing(self, event=0):
        self.destroy()


if __name__ == "__main__":
    app = App()
    app.mainloop()
