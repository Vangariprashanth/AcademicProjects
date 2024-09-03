using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

/**
* @author Abdelnasser Ouda
*
*/

namespace Sample_MVC
{
    public partial class View : Form
    {
        Controller my_controller;
        Model my_model;

        public View()
        {
            InitializeComponent();

            my_controller = new Controller();
            my_model = new Model();
            this.Connect_btn.Click += new System.EventHandler(my_controller.Connect_btn_Click);
            this.Send_btn.Click += new System.EventHandler(my_controller.Send_btn_Click);
            this.Receive_btn.Click += new System.EventHandler(my_controller.Receive_btn_Click);
        }

        public String GetMsg()
        {
            return this.Send_Box.Text.ToString();
        }

        // update the view
        public void SetMsg()
        {
            this.Msg.Text = my_model.Get_From_TCP_server(); 
        }


        // This delegate enables asynchronous calls for  setting
        // the text property on a Msg control from extrnal thread.
        delegate void SetInfoCallback(string info);

        // we will use our delegate to create a refrence to this method  
        public void add_text(String _msg)
        {
            this.Msg.Text += _msg;
        }

        // this methos will be called (instead of SetMsg above) from extranl thread to update Msg control
        public void SetInfoBox(String _msg)
        {
            string text = _msg;
            SetInfoCallback d = new SetInfoCallback(add_text);
            this.Invoke(d, new object[] { text });
        }

        private void View_Load(object sender, EventArgs e)
        {

        }

        private void Send_Box_TextChanged(object sender, EventArgs e)
        {

        }

        private void Msg_Click(object sender, EventArgs e)
        {

        }

    }
}
