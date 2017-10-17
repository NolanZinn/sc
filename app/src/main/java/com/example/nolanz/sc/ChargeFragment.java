package com.example.nolanz.sc;

import android.app.Dialog;
import android.app.TimePickerDialog;
import android.content.Context;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.Fragment;
import android.support.v4.app.NotificationCompat;
import android.text.format.DateFormat;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.TimePicker;

import org.w3c.dom.Text;

import java.sql.Time;
import java.util.Calendar;

/**
 * Created by Nolan Z on 10/13/2017.
 */

public class ChargeFragment extends Fragment {
    Button setTime, startChg, stopChg;
    Switch ssc;
    TextView time;
    Context context;
    private int hour, minute;



    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_charge, container, false);
        context = getContext();
        setTime = view.findViewById(R.id.setTime);
        startChg = view.findViewById(R.id.startCharge);
        stopChg = view.findViewById(R.id.stopCharge);
        ssc = view.findViewById(R.id.sscOnOff);
        time = view.findViewById(R.id.time);

        setTime.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                TimePickerDialog timePickerDialog = new TimePickerDialog(context, timePickerListener, 0, 0, false);
                timePickerDialog.show();
            }
        });


        return view;
    }

    private TimePickerDialog.OnTimeSetListener timePickerListener =
            new TimePickerDialog.OnTimeSetListener() {
                public void onTimeSet(TimePicker view, int selectedHour,
                                      int selectedMinute) {
                    hour = selectedHour;
                    minute = selectedMinute;
                    String AM_PM = "AM";
                    if(hour >=12)
                        AM_PM = "PM";


                    // set current time into textview
                    time.setText(new StringBuilder().append(padH(hour))
                            .append(":").append(padM(minute)).append(" " + AM_PM));
                }
            };

    private static String padH(int c) {
        if (c >= 10) {
            if (c <= 12) {
                return String.valueOf(c);
            } else {
                return "0" + String.valueOf(c - 12);
            }
        }
        else if(c == 0)
            return String.valueOf(12);
        else
            return "0" + String.valueOf(c);
    }

    private static String padM(int c) {
        if (c >= 10)
            return String.valueOf(c);
        else
            return "0" + String.valueOf(c);
    }


    @Override
    public void onResume() {
        super.onResume();
    }

    @Override
    public void onPause() {
        super.onPause();
    }

    @Override
    public void onStop() {
        super.onStop();
    }
}


