object Form_proycom: TForm_proycom
  Left = 285
  Top = 190
  Width = 719
  Height = 177
  Caption = 'Proyección y Comparativos'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 711
    Height = 89
    Align = alTop
    Caption = 'Clientes de:'
    TabOrder = 0
    object Label1: TLabel
      Left = 17
      Top = 18
      Width = 60
      Height = 13
      Caption = 'Fecha Inicial'
    end
    object Label2: TLabel
      Left = 22
      Top = 40
      Width = 55
      Height = 13
      Caption = 'Fecha Final'
    end
    object btn_aceptar: TBitBtn
      Left = 349
      Top = 20
      Width = 75
      Height = 25
      Caption = 'Aceptar'
      TabOrder = 3
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
    end
    object btn_cancelar: TBitBtn
      Left = 429
      Top = 20
      Width = 75
      Height = 25
      Cancel = True
      Caption = 'Cancelar'
      TabOrder = 4
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        333333333333333333333333000033338833333333333333333F333333333333
        0000333911833333983333333388F333333F3333000033391118333911833333
        38F38F333F88F33300003339111183911118333338F338F3F8338F3300003333
        911118111118333338F3338F833338F3000033333911111111833333338F3338
        3333F8330000333333911111183333333338F333333F83330000333333311111
        8333333333338F3333383333000033333339111183333333333338F333833333
        00003333339111118333333333333833338F3333000033333911181118333333
        33338333338F333300003333911183911183333333383338F338F33300003333
        9118333911183333338F33838F338F33000033333913333391113333338FF833
        38F338F300003333333333333919333333388333338FFF830000333333333333
        3333333333333333333888330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
    end
    object date_fecfin: TDateTimePicker
      Left = 82
      Top = 37
      Width = 89
      Height = 21
      CalAlignment = dtaLeft
      Date = 37193
      Time = 37193
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 1
    end
    object date_fecini: TDateTimePicker
      Left = 83
      Top = 15
      Width = 89
      Height = 21
      CalAlignment = dtaLeft
      Date = 37193
      Time = 37193
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 0
      OnExit = date_feciniExit
    end
    object GroupBox2: TGroupBox
      Left = 180
      Top = 9
      Width = 149
      Height = 72
      Caption = 'Clientes de :'
      TabOrder = 2
      object rbtn_fona: TRadioButton
        Left = 8
        Top = 15
        Width = 65
        Height = 17
        Caption = 'Fonacot'
        TabOrder = 0
      end
      object rbtn_ime: TRadioButton
        Left = 88
        Top = 16
        Width = 50
        Height = 17
        Caption = 'Imevi'
        TabOrder = 1
      end
      object rbtn_menu: TRadioButton
        Left = 9
        Top = 34
        Width = 65
        Height = 17
        Caption = 'Menudeo'
        TabOrder = 2
      end
      object rbtn_fide: TRadioButton
        Left = 88
        Top = 33
        Width = 50
        Height = 17
        Caption = 'Fide'
        TabOrder = 3
      end
      object rbtn_total: TRadioButton
        Left = 9
        Top = 52
        Width = 50
        Height = 17
        Caption = 'Total'
        Checked = True
        TabOrder = 4
        TabStop = True
      end
    end
  end
  object qry_subproycom: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select * from subproycom where zona= :ZONA and subzona= :SUBZON ' +
        'and cia= :CIA order by zona')
    Left = 388
    Top = 50
    ParamData = <
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SUBZON'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_ubivtas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select * from ubivtainv where pvta = :PTVA and zonainv = :ZONA o' +
        'rder by zonacar')
    Left = 420
    Top = 50
    ParamData = <
      item
        DataType = ftString
        Name = 'PTVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end>
  end
  object qry_tabcvta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select sum(ctovtasi+ctovtano/(1 + (:IVA /100))) as  sumas,'
      
        #9'sum(ctocont /( 1 + :IVA /100 )) as contado, sum(ctocred / (1 + ' +
        ':IVA / 100)) as credito'
      #9'from tabcvta'
      
        'where almkdx= :ALM and ptvta= :PTVA and fecini between :FECINI a' +
        'nd :FECFIN'
      'and cia= :CIA and tipoent=:TIPOENT'
      'and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      ') and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fecini))')
    Left = 468
    Top = 50
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PTVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TIPOENT'
        ParamType = ptUnknown
      end>
  end
  object qry_tabcvta2: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select sum(ctovtasi+ctovtano/(1 + (:IVA /100))) as sumas,'
      
        #9'sum(ctocont /( 1 + :IVA /100 )) as contado, sum(ctocred / (1 + ' +
        ':IVA / 100)) as credito '
      #9'from tabcvta'
      #9'where almkdx= :ALM and fecini between :FECINI and :FECFIN'
      'and cia= :CIA and tipoent=:TIPOENT'
      'and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      ')'
      'and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fecini))')
    Left = 500
    Top = 50
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TIPOENT'
        ParamType = ptUnknown
      end>
  end
  object qry_tipocredi: TQuery
    DatabaseName = 'dbcartera'
    SQL.Strings = (
      
        'select sum(precon) as credito from car_tipocardet a join acuvtas' +
        ' b'
      #9'on a.ticte = b.ticte  where zona= :ZONA'
      
        #9'and fecini= :FECINI and fecfin= :FECFIN and voc= '#39'V'#39' and qom <>' +
        ' '#39'C'#39'  and a.idtipocar= :IDECAR')
    Left = 548
    Top = 50
    ParamData = <
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDECAR'
        ParamType = ptUnknown
      end>
  end
  object qry_proycom: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.*,b.nombre from proycom a join zonainv b on a.zona = b.' +
        'zona order by a.zona')
    Left = 358
    Top = 50
  end
  object qry_tipocont: TQuery
    DatabaseName = 'dbcartera'
    SQL.Strings = (
      
        'select sum(precon) as contado from car_tipocardet a join acuvtas' +
        ' b'
      #9'on a.ticte = b.ticte  where zona= :ZONA'
      
        #9'and fecini= :FECINI and fecfin= :FECFIN and voc= '#39'V'#39' and qom = ' +
        #39'C'#39'  and a.idtipocar= :IDECAR')
    Left = 580
    Top = 50
    ParamData = <
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDECAR'
        ParamType = ptUnknown
      end>
  end
  object qry_tipocardet1: TQuery
    DatabaseName = 'dbcartera'
    SQL.Strings = (
      
        'select sum(precon) as credito from car_tipocardet a join acuvtas' +
        ' b'
      #9'on a.ticte = b.ticte  where zona= :ZONA and subzona= :SUBZON'
      
        #9'and fecini= :FECINI and fecfin= :FECFIN and voc='#39'V'#39' and qom <> ' +
        #39'C'#39' and a.idtipocar= :IDETIP')
    Left = 620
    Top = 50
    ParamData = <
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SUBZON'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDETIP'
        ParamType = ptUnknown
      end>
  end
  object qry_tipocardet2: TQuery
    DatabaseName = 'dbcartera'
    SQL.Strings = (
      
        'select sum(precon) as contado from car_tipocardet a join acuvtas' +
        ' b'
      #9'on a.ticte = b.ticte  where zona= :ZONA and subzona= :SUBZON'
      
        #9'and fecini= :FECINI and fecfin= :FECFIN and voc='#39'V'#39' and qom = '#39 +
        'C'#39' and a.idtipocar= :IDETIP')
    Left = 660
    Top = 50
    ParamData = <
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SUBZON'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDETIP'
        ParamType = ptUnknown
      end>
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 416
    Top = 104
    object reporte_proycom: TAction
      Caption = 'Reporte'
      ImageIndex = 21
      OnExecute = reporte_proycomExecute
    end
  end
end
