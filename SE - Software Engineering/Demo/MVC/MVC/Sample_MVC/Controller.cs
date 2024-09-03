using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

/**
* @author Abdelnasser Ouda
*
*/

namespace Sample_MVC
{
    class Controller
    {
        private static View _view;
        private Model my_model;

        public void Connect_btn_Click(object sender, EventArgs e)
        {
            MessageBox.Show("The Controller received this event.\nThe Controller will then create a connection through the Model\n\nThis message from the Controller");
            my_model = new Model();
            my_model.Connect_to_TCP_server();    
        }

        public void Send_btn_Click(object sender, EventArgs e)
        {
            _view = (View)((Button)sender).FindForm();
            string msg = _view.GetMsg();

            MessageBox.Show("The Controller received this event.\nThe Controller will request the model to send the text \""+ msg + "\" to the server\n\nThis message from the Controller");

     
            my_model.Send_to_TCP_server(msg);
        }

        public void Receive_btn_Click(object sender, EventArgs e)
        {
            
            MessageBox.Show("The Controller received this event.\nThe Controller will request the model to get the message from the server\n\nThis message from the Controller");

            _view = (View)((Button)sender).FindForm();
            _view.SetMsg();
            MessageBox.Show("The Controller has updated the view.\n \nThis message from the Controller");

        }
    }
}
